/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:29 by tyou              #+#    #+#             */
/*   Updated: 2021/06/28 20:26:24 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			clear_state(t_state *t)
{
	int	i;

	usleep(1000 * 1000);
	if (t->philos)
	{
		i = 0;
		while (i < t->amount)
			pthread_mutex_destroy(&t->philos[i++].eat_m);
		free(t->philos);
	}
	if (t->forks_m)
	{
		i = 0;
		while (i < t->amount)
			pthread_mutex_destroy(&t->forks_m[i++]);
		free(t->forks_m);
	}
	pthread_mutex_destroy(&t->write_m);
	pthread_mutex_destroy(&t->somebody_dead_m);
}
