/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:05:16 by tyou              #+#    #+#             */
/*   Updated: 2021/06/27 23:54:40 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EAT 0
# define SLEEP 1
# define THINK 2
# define TAKEN_FORK 3
# define DIED 4
# define OVER 5

# define S_FORK		"SemaphoreFork"
# define S_WRITE	"SemaphoreWrite"
# define S_DEAD		"SemaphoreDead"
# define S_DEADW	"SemaphoreDeadWrite"
# define S_PHILOEAT	"SemaphorePhiloEat"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_philo
{
	struct s_state	*state;
	pid_t			pid;
	int				position;
	int				is_eating;
	int				limit;
	int				last_eat;
	int				eat_count;
	sem_t			*eat_s;
}					t_philo;
typedef struct		s_state
{
	int				amount;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				start;
	t_philo			*philos;
	sem_t			*forks_s;
	sem_t			*write_s;
	sem_t			*somebody_dead_s;
	sem_t			*dead_write_s;
}					t_state;

char				*cs(char *buf, int i);
int					ft_atoi(const char *str);
int					prnt(t_philo *philo, int sign);
int					get_time(void);
int					err(char *str);
int					init(t_state *t, int ac, char **av);
void				clear_state(t_state *t);
void				take_forks(t_philo *philo);
void				clean_forks(t_philo *philo);
void				eating(t_philo *philo);
void				check_usleep(int time, t_philo *philo);

#endif
