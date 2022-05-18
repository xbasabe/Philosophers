/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:29:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/05/18 17:55:11 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo2 *phil)
{
	long			time;
	struct timeval	now;

	pthread_mutex_lock(&phil->forks[phil->l_fork]);
	pthread_mutex_lock(&phil->forks[phil->r_fork]);
	is_alive(phil);
	prin("takes a fork", phil);
	prin("takes a fork", phil);
	prin("is eating", phil);
	phil->eaten--;
	if (phil->eaten <= 0)
		kill(phil);
	phil->remain = phil->data->die;
	//printf("   --philo %d eat IN remain %ld.\n", phil->philo_num, phil->remain);
	timer(phil->data->eat, phil);
	//pthread_mutex_lock(&phil->data->print);
	//printf("   --philo %d eat OUT remain %ld.\n", phil->philo_num, phil->remain);
	//pthread_mutex_unlock(&phil->data->print);
	//gettimeofday(&now, NULL);
	//time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	//phil->last_meal = time;
	//is_alive(phil);
	//remain_live(phil);
	//phil->remain = phil->data->die;
	pthread_mutex_unlock(&phil->forks[phil->r_fork]);
	pthread_mutex_unlock(&phil->forks[phil->l_fork]);
}

void	sleeping(t_philo2 *phil)
{
	prin("is sleeping", phil);
	//printf("   --philo %d sleep in remain %ld.\n", phil->philo_num, phil->remain);
	timer(phil->data->sleep, phil);
	//printf("   --philo %d sleep out remain %ld.\n", phil->philo_num, phil->remain);
}

void	thinking(t_philo2 *phil)
{
	//is_alive(phil);
	prin("is thinking", phil);
	//is_alive(phil);
}

void	kill2(t_philo2 *phil)
{
	prin("killed 2", phil);
	//phil->data->kill_all = 1;
	exit (0);
}

void	kill(t_philo2 *phil)
{
	prin("died", phil);
	pthread_mutex_lock(&phil->data->dead);
	phil->data->kill_all = 1;
	pthread_mutex_unlock(&phil->data->dead);
	exit (0);
}

void	*philoing(void *data)
{
	t_philo2		*phil;

	phil = (t_philo2 *)data;
	prin("created", phil);
	phil->remain = phil->data->die;
	//phil->born = time;
	//pthread_mutex_lock(&phil->data->dead);
	//while (1)
	while (phil->data->kill_all == 0)
	{
		is_alive(phil);
		eating(phil);
		//printf("  -philo %d eat remain %ld.\n", phil->philo_num, phil->remain);
		is_alive(phil);
		sleeping(phil);
		//printf("  -philo %d sleep remain %ld.\n", phil->philo_num, phil->remain);
		is_alive(phil);
		thinking(phil);
		//printf("  -philo %d sleep remain %ld.\n", phil->philo_num, phil->remain);
		is_alive(phil);
	}
	return (NULL);
}
