/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:42:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/24 13:22:33 by xbasabe-         ###   ########.fr       */
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


typedef struct s_philo2
{
	int				philos;
	long			die;
	long			eat;
	long			sleep;
	int				meals;
	int				philo_num;
	int				l_fork;
	int				r_fork;
	long			start;
	long			last_meal;
	long			remain;
	int				kill_them;
	pthread_mutex_t	*forks;
}				t_philo2;

int		timer(long wait);
int		live_sleep(t_philo2 *phil);
int		live_eating(t_philo2 *phil);
int		live_thinking(t_philo2 *phil);
void	creat_threads(pthread_mutex_t	*forks, t_philo2 philo);
void	*philoing(void *data);
void	kill(t_philo2 *phil);
void	init_struct(t_philo2 *phil, char **argv);
void	init_mutex(pthread_mutex_t	*forks, int numb_philos);
void	acces_fork(t_philo2 *philo);
void	init_philo(t_philo2 phil, t_philo2 *philias);
void 	is_alive(t_philo2 *phil);

#endif
