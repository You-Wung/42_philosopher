/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:31:56 by tyou              #+#    #+#             */
/*   Updated: 2021/09/27 00:45:17 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t			get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
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
	static int	done;

	pthread_mutex_lock(&philo->state->write_m);
	if (done == 0)
	{
		if (sign == DIED || sign == OVER)
			done = 1;
		if (sign == OVER)
			printf("%llu\t%s", get_time() - philo->state->start,
				get_message(sign));
		else
			printf("%llu\t %d %s", get_time() - philo->state->start,
				philo->position + 1, get_message(sign));
	}
	pthread_mutex_unlock(&philo->state->write_m);
	return (0);
}
