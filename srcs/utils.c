/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:30:13 by marvin            #+#    #+#             */
/*   Updated: 2022/05/25 12:30:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	plot(char *str, t_philo2 *phil)
{
	long			time;
	long			stamp;
	struct timeval	now;

	pthread_mutex_lock(&phil->data->print);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - phil->data->start;
	//stamp = time - phil->born;
	if (phil->data->kill_all == 0)
		printf("[%ld] philo %d %s  remain %ld\n", stamp, phil->philo_num, str, phil->data->remain[(phil->philo_num) - 1]);
	pthread_mutex_unlock(&phil->data->print);
}

void	plot2(char *str, t_comon *gen, int p_num)
{
	long			time;
	long			stamp;
	struct timeval	now;

	pthread_mutex_lock(&gen->print);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - gen->start;
	//stamp = time - phil->born;
	if (gen->kill_all == 0)
		printf("[%ld] philo %d %s.\n", stamp, p_num, str);
	pthread_mutex_unlock(&gen->print);
}

int check_meals(t_philo2 *phil)
{
    phil->eaten--;
	if (phil->eaten == 0)
	{
		phil->data->meals--;
		if(phil->data->meals == 0)
		{
			kill(phil->data, phil->philo_num);
			pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
			pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
			return(1);
		}
	}
    return(0);
}
