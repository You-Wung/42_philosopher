/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:00 by tyou              #+#    #+#             */
/*   Updated: 2021/09/27 23:49:39 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	prnt(philo, TAKEN_FORK);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	prnt(philo, TAKEN_FORK);
}

void		clean_forks(t_philo *philo)
{
	prnt(philo, SLEEP);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	//usleep(philo->state->time_to_sleep * 1000);
	check_usleep(philo->state->time_to_sleep, philo);
}
