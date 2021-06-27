/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:10 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 23:44:47 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			check_usleep(int time, t_philo *philo)
{
	int				i;

	i = get_time() - philo->state->start;
	time += get_time() - philo->state->start;
	while (i < time)
	{
		usleep(100);
		i = get_time() - philo->state->start;
	}
}

void			eating(t_philo *philo)
{
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	philo->eat_count++;
	prnt(philo, EAT);
	check_usleep(philo->state->time_to_eat, philo);
	philo->is_eating = 0;
	sem_post(philo->eat_s);
}
