/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:42:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/07/14 10:40:44 by xbasabe-         ###   ########.fr       */
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
	int				philos;
	long			die;
	long			eat;
	long			sleep;
	int				meals;
	int				*done;
	long			start;
	int				kill_all;
	long			last_check;
	pthread_mutex_t	dead;
	pthread_mutex_t	updating;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	long			*remain;
}	t_comon;

typedef struct s_philo2
{
	int				philo_num;
	int				l_fork;
	int				r_fork;
	long			born;
	int				eaten;
	t_comon			*data;
}				t_philo2;

int		timer(long wait, t_philo2 *phil);
void	creat_threads(pthread_mutex_t	*forks, t_comon data);
void	*philoing(void *data);
void	init_struct(t_comon *data, char **argv);
void	init_mutex(pthread_mutex_t	*forks, int numb_philos);
void	acces_fork(t_philo2 *philo);
void	init_philo(t_philo2 phil, t_philo2 *philias);
void	plot(char *str, t_philo2 *phil);
void	*remain_live(void *data);
int		eating(t_philo2 *phil);
int		sleeping(t_philo2 *phil);
int		thinking(t_philo2 *phil);
int		update(t_comon *phil);
int		check_meals(t_philo2 *phil);
void	kill(t_comon *gen, int p_num);
void	plot2(char *str, t_comon *gen, int p_num);
int		all_alive(t_philo2 *phil);
void	unlock_fork(t_comon *gen, int p_num);
void	kill2(t_comon *gen, int p_num);
int		update_meals(t_philo2 *phil);
void	free_threads( pthread_mutex_t	*forks,
			pthread_t	*phil_id, t_philo2	*philias);

#endif
