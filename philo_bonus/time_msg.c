/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:31:56 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 23:12:23 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int					get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

static char			*get_message(int sign)
{
	if (sign == EAT)
		return (" is eating\n");
	else if (sign == SLEEP)
		return (" is sleeping\n");
	else if (sign == TAKEN_FORK)
		return (" has taken a fork\n");
	else if (sign == THINK)
		return (" is thinking\n");
	else if (sign == OVER)
		return (" must eat count reached\n");
	return (" died\n");
}

int					prnt(t_philo *philo, int sign)
{
	sem_wait(philo->state->write_s);
	sem_wait(philo->state->dead_write_s);
	if (sign == OVER)
		printf("%d\t%s", get_time() - philo->state->start,
			get_message(sign));
	else
		printf("%d\t %d %s", get_time() - philo->state->start,
			philo->position + 1, get_message(sign));
	if (sign < DIED)
		sem_post(philo->state->dead_write_s);
	sem_post(philo->state->write_s);
	return (0);
}
