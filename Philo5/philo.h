/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:42:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 13:15:13 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>


typedef struct s_comon
{
	int		philos;
	long	die;
	long	eat;
	long	sleep;
	int		meals;
	long	start;
	int		kill_all;
}	t_comon;

typedef struct s_philo2
{
	int				philo_num;
	int				l_fork;
	int				r_fork;
	long			born;
	long			last_meal;
	long			remain;
	int				eaten;
	t_comon			*data;
	pthread_mutex_t	*forks;
}				t_philo2;

int		timer(long wait);
int		live_sleep(t_philo2 *phil);
int		live_eating(t_philo2 *phil);
int		live_thinking(t_philo2 *phil);
void	creat_threads(pthread_mutex_t	*forks, t_comon data);
void	*philoing(void *data);
void	kill(t_philo2 *phil);
void	kill2(t_philo2 *phil);
void	init_struct(t_comon *data, char **argv);
void	init_mutex(pthread_mutex_t	*forks, int numb_philos);
void	acces_fork(t_philo2 *philo);
void	init_philo(t_philo2 phil, t_philo2 *philias);
void 	is_alive(t_philo2 *phil);

#endif
