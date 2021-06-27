/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:07:26 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 00:27:12 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*must_monitor(void *s)
{
	t_state *state;
	int		i;
	int		total;

	state = (t_state*)s;
	total = 0;
	while (total < state->must_eat_count)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_lock(&state->philos[i++].eat_m);
		total++;
	}
	prnt(&state->philos[0], OVER);
	pthread_mutex_unlock(&state->somebody_dead_m);
	return ((void *)0);
}

void		*monitor(void *philo_v)
{
	t_philo *philo;

	philo = (t_philo *)philo_v;
	while (1)
	{
		if (!philo->is_eating && get_time() > philo->limit)
		{
			prnt(philo, DIED);
			pthread_mutex_unlock(&philo->state->somebody_dead_m);
			return ((void *)0);
		}
	}
	return ((void *)0);
}

void		*routine(void *philo_copy)
{
	t_philo		*philo;
	pthread_t	tip;

	philo = (t_philo *)philo_copy;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	pthread_create(&tip, 0, &monitor, philo);
	pthread_detach(tip);
	while (1)
	{
		take_forks(philo);
		eating(philo);
		clean_forks(philo);
		prnt(philo, THINK);
	}
	return ((void *)0);
}

int			start_threads(t_state *t)
{
	pthread_t	tid;
	int			i;
	void		*philo;

	t->start = get_time();
	if (t->must_eat_count > 0)
	{
		pthread_create(&tid, 0, &must_monitor, (void *)t);
		pthread_detach(tid);
	}
	i = -1;
	while (++i < t->amount)
	{
		philo = (void *)&t->philos[i];
		pthread_create(&tid, 0, &routine, philo);
		pthread_detach(tid);
		usleep(100);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_state t;

	if (ac < 5 || ac > 6)
		return (err("error : bad arguments"));
	init(&t, ac, av);
	start_threads(&t);
	pthread_mutex_lock(&t.somebody_dead_m);
	pthread_mutex_unlock(&t.somebody_dead_m);
	clear_state(&t);
	return (0);
}
