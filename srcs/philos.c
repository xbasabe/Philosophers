/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:29:52 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/06/07 12:10:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo2 *phil)
{
	pthread_mutex_lock(&phil->data->forks[phil->l_fork]);
	plot2("has taken a fork", phil->data, phil->philo_num);
	pthread_mutex_lock(&phil->data->forks[phil->r_fork]);
	if (all_alive(phil) == 2)
	{
		pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
		pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
		return(1);
	}
	plot2("has taken a fork", phil->data, phil->philo_num);
	pthread_mutex_lock(&phil->data->updating);
	phil->data->remain[phil->philo_num - 1] = phil->data->die;
	pthread_mutex_unlock(&phil->data->updating);
	plot2("is eating", phil->data, phil->philo_num);
	if(check_meals(phil) == 1)
		return(1);
	if (timer(phil->data->eat, phil) != 0)
	{
		pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
		pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
		return(1);
	}
	pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
	pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
	return(0);
}

int	sleeping(t_philo2 *phil)
{
	if (all_alive(phil) != 0)
		return(1);
	plot2("is sleeping", phil->data, phil->philo_num);
	if (timer(phil->data->sleep, phil) !=0)
		return(1);
	if (all_alive(phil) != 0)
		return(1);
	return(0);
}

int	thinking(t_philo2 *phil)
{
	if (all_alive(phil) != 0)
		return(1);
	plot2("is thinking", phil->data, phil->philo_num);
	return(0);
}

void	kill(t_comon *gen, int p_num)
{
	pthread_mutex_lock(&gen->dead);
	plot2("died", gen, p_num);
	gen->kill_all = 1;
	unlock_fork(gen, p_num);
	pthread_mutex_unlock(&gen->dead);
}

void	*philoing(void *data)
{
	t_philo2		*phil;
	struct timeval	now;

	phil = (t_philo2 *)data;
	gettimeofday(&now, NULL);
	phil->born = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	phil->data->last_check = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	while (phil->data->kill_all == 0)
	{
		if (eating(phil) != 0)
			break ;
		if(sleeping(phil) != 0)
			break ;
		if (thinking(phil) != 0)
			break ;
	}
	return (NULL);
}
