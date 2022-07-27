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

void	plot2(char *str, t_comon *gen, int p_num)
{
	long			time;
	long			stamp;
	struct timeval	now;

	pthread_mutex_lock(&gen->print);
	gettimeofday(&now, NULL);
	time = (now.tv_usec / 1000) + (now.tv_sec * 1000);
	stamp = time - gen->start;
	if (gen->kill_all == 0)
		printf("[%ld] philo %d %s.\n", stamp, p_num, str);
	pthread_mutex_unlock(&gen->print);
}

int	update_meals(t_philo2 *phil)
{
	phil->eaten--;
	if (phil->eaten == 0)
		phil->data->done[phil->philo_num - 1] = 0;
	return (0);
}

int	check_meals(t_philo2 *phil)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < phil->data->philos)
	{
		flag = flag + phil->data->done[i];
		i++;
	}
	if (flag == 0)
	{
		kill2(phil->data, phil->philo_num);
		pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
		pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
		return (1);
	}
	return (0);
}

void	kill2(t_comon *gen, int p_num)
{
	pthread_mutex_lock(&gen->dead);
	gen->kill_all = 1;
	unlock_fork(gen, p_num);
	pthread_mutex_unlock(&gen->dead);
}
