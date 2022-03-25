/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:29:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 13:52:32 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo2 *phil)
{
	long			time;
	long			stamp;
	struct timeval	now;

	pthread_mutex_lock(&phil->forks[phil->l_fork]);
	pthread_mutex_lock(&phil->forks[phil->r_fork]);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] philo %d ", stamp, phil->philo_num);
	printf("takes fork %d.\n", phil->l_fork);
	printf("[%ld] philo %d", stamp, phil->philo_num);
	printf(" takes fork %d.\n", phil->r_fork);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] philo %d is eating.\n", stamp, phil->philo_num);
	timer(phil->data->eat);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	phil->last_meal = time;
	is_alive(phil);
	phil->remain = phil->data->die;
	phil->eaten--;
	if (phil->eaten <= 0)
		kill(phil);
	pthread_mutex_unlock(&phil->forks[phil->r_fork]);
	pthread_mutex_unlock(&phil->forks[phil->l_fork]);
}

void	sleeping(t_philo2 *phil)
{
	long			time;
	long			stamp;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] philo %d is sleeping.\n", stamp, phil->philo_num);
	timer(phil->data->sleep);
	is_alive(phil);
	if (phil->remain <= 0)
		kill(phil);
}

void	thinking(t_philo2 *phil)
{
	long			time;
	struct timeval	now;
	long			stamp;

	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] philo %d is thinking.\n", stamp, phil->philo_num);
	is_alive(phil);
}

void	kill2(t_philo2 *phil)
{
	long			time;
	long			stamp;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] kill them all.\n", stamp);
	phil->data->kill_all = 1;
	//pthread_mutex_destroy(&phil->forks[phil->l_fork]);
	//pthread_mutex_destroy(&phil->forks[phil->r_fork]);
	//free(phil->forks);
	//free(phil->thread_id);
	exit (0);
}

void	kill(t_philo2 *phil)
{
	long			time;
	long			stamp;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] philo %d died.\n", stamp, phil->philo_num);
	phil->data->kill_all = 1;
	//pthread_mutex_destroy(&phil->forks[phil->l_fork]);
	//pthread_mutex_destroy(&phil->forks[phil->r_fork]);
	//free(phil->forks);
	//free(phil->thread_id);
	usleep(100);
	exit (0);
}

void	*philoing(void *data)
{
	t_philo2		*phil;
	long			time;
	long			stamp;
	struct timeval	now;

	phil = (t_philo2 *)data;
	if (phil->philo_num % 2 != 0)
		usleep(100);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	printf("[%ld] created philo %d.\n", stamp, phil->philo_num);
	phil->born = time;
	while (1)
	{

		eating(phil);
		if(phil->data->kill_all == 1)
			kill2(phil);
		sleeping(phil);
		if(phil->data->kill_all == 1)
			kill2(phil);
		thinking(phil);
		if(phil->data->kill_all == 1)
			kill2(phil);
	}
	
	return (NULL);
}
