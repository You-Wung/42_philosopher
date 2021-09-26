/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:10 by tyou              #+#    #+#             */
/*   Updated: 2021/09/27 00:49:30 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			check_usleep(uint64_t time, t_philo *philo)
{
	uint64_t		i;

	i = get_time() - philo->state->start;
	time += get_time() - philo->state->start;
	while (i <= time)
	{
		usleep(10000);
		i = get_time() - philo->state->start;
	}
}

void			eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	prnt(philo, EAT);
	check_usleep(philo->state->time_to_eat, philo);
	//usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}
