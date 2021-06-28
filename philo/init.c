/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:18:55 by tyou              #+#    #+#             */
/*   Updated: 2021/06/28 18:01:26 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_sem(t_state *t)
{
	int	i;

	pthread_mutex_init(&t->write_m, NULL);
	pthread_mutex_init(&t->somebody_dead_m, NULL);
	pthread_mutex_lock(&t->somebody_dead_m);
	t->forks_m = (pthread_mutex_t*)malloc(sizeof(*(t->forks_m)) * t->amount);
	i = 0;
	while (i < t->amount)
		pthread_mutex_init(&t->forks_m[i++], NULL);
	return (0);
}

static int	init_philos(t_state *t)
{
	int		i;

	i = -1;
	while (++i < t->amount)
	{
		t->philos[i].is_eating = 0;
		t->philos[i].position = i;
		t->philos[i].lfork = i;
		t->philos[i].rfork = (i + 1) % t->amount;
		t->philos[i].eat_count = 0;
		t->philos[i].state = t;
		pthread_mutex_init(&t->philos[i].mutex, NULL);
		pthread_mutex_init(&t->philos[i].eat_m, NULL);
		pthread_mutex_lock(&t->philos[i].eat_m);
	}
	return (0);
}

int			init(t_state *t, int ac, char **av)
{
	t->amount = ft_atoi(av[1]);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		t->must_eat_count = ft_atoi(av[5]);
	else
		t->must_eat_count = 0;
	if (t->amount > 200 || t->time_to_die < 60 ||
			t->time_to_sleep < 60 || t->time_to_eat < 60 || t->amount < 1)
		return (err("error : during init"));
	t->philos = (t_philo *)malloc(sizeof(*(t->philos)) * t->amount);
	init_philos(t);
	init_sem(t);
	return (0);
}
