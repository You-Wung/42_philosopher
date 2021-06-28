/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:05:16 by tyou              #+#    #+#             */
/*   Updated: 2021/06/28 16:11:30 by tyou             ###   ########.fr       */
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
	int				limit;
	int				last_eat;
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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				start;
	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}					t_state;

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
