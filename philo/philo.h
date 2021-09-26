/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:05:16 by tyou              #+#    #+#             */
/*   Updated: 2021/09/27 00:47:06 by tyou             ###   ########.fr       */
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
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_state	*state;
	pthread_mutex_t	eat_m;
	pthread_mutex_t	mutex;
}					t_philo;
typedef struct		s_state
{
	int				amount;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		start;
	int				must_eat_count;
	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}					t_state;

int					ft_atoi(const char *str);
int					prnt(t_philo *philo, int sign);
uint64_t			get_time(void);
int					err(char *str);
int					init(t_state *t, int ac, char **av);
void				clear_state(t_state *t);
void				take_forks(t_philo *philo);
void				clean_forks(t_philo *philo);
void				eating(t_philo *philo);
void				check_usleep(uint64_t time, t_philo *philo);

#endif
