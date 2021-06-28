/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 01:12:29 by tyou              #+#    #+#             */
/*   Updated: 2021/06/28 21:03:09 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void			clear_state(t_state *t)
{
	int		i;

	i = 0;
	sem_close(t->forks_s);
	sem_close(t->write_s);
	sem_close(t->dead_write_s);
	sem_close(t->somebody_dead_s);
	if (t->philos)
	{
		i = -1;
		while (++i < t->amount)
		{
			sem_close(t->philos[i].eat_s);
			sem_unlink(cs(S_PHILOEAT, i));
		}
		free(t->philos);
	}
	sem_unlink(S_FORK);
	sem_unlink(S_WRITE);
	sem_unlink(S_DEAD);
	sem_unlink(S_DEADW);
}
