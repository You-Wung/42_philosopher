/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:18:55 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 23:22:13 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char		*cs(char *buf, int i)
{
	static char	rt[50];
	int			j;

	j = -1;
	while (++j < 49)
		rt[j] = 0;
	j = -1;
	while (buf[++j])
		rt[j] = buf[j];
	rt[j++] = i + '0';
	rt[j] = '\0';
	return (&rt[0]);
}

static int	init_sem(t_state *t)
{
	sem_unlink(S_WRITE);
	sem_unlink(S_FORK);
	sem_unlink(S_DEAD);
	sem_unlink(S_DEADW);
	t->forks_s = sem_open(S_FORK, O_CREAT, 644, t->amount);
	t->write_s = sem_open(S_WRITE, O_CREAT, 644, 1);
	t->somebody_dead_s = sem_open(S_DEAD, O_CREAT, 644, 0);
	t->dead_write_s = sem_open(S_DEADW, O_CREAT, 644, 1);
	return (0);
}

static int	init_philos(t_state *t)
{
	int		i;

	i = -1;
	while (++i < t->amount)
	{
		t->philos[i].state = t;
		t->philos[i].is_eating = 0;
		t->philos[i].position = i;
		sem_unlink(cs(S_PHILOEAT, i));
		t->philos[i].eat_s = sem_open(cs(S_PHILOEAT, i), O_CREAT, 644, 0);
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
