/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:00 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 23:43:36 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		take_forks(t_philo *philo)
{
	sem_wait(philo->state->forks_s);
	prnt(philo, TAKEN_FORK);
	sem_wait(philo->state->forks_s);
	prnt(philo, TAKEN_FORK);
}

void		clean_forks(t_philo *philo)
{
	sem_post(philo->state->forks_s);
	sem_post(philo->state->forks_s);
	prnt(philo, SLEEP);
	check_usleep(philo->state->time_to_sleep, philo);
}
