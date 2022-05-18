/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:24:35 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/05/18 17:49:08 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timer(long wait, t_philo2 *phil)
{
	long			count;
	long			init;
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	count = 0;
	init = (start.tv_usec / 1000) + (start.tv_sec * 1000);
	//printf("   --philo %d IN remain %ld.\n", phil->philo_num, phil->remain);
	while (count < wait)
	{
		gettimeofday(&now, NULL);
		usleep(100);
		count = (now.tv_usec / 1000) + (now.tv_sec * 1000) - init;
		if (phil->data->kill_all == 1 || phil->remain == count)
		{
			printf("   --philo %d killed timer2 %ld.\n", phil->philo_num, phil->remain);
			kill(phil);
		}
	}
	phil->remain -= count;
	//printf("   --philo %d OUT remain %ld.\n", phil->philo_num, phil->remain);
	return (0);
}

void is_alive(t_philo2 *phil)
{
	long			n;
	long			timing;
	struct timeval	now;

	gettimeofday(&now, NULL);
	n = now.tv_sec * 1000 + now.tv_usec / 1000;
	timing = n - phil->last_meal;
	if (phil->data->kill_all == 1 || phil->remain <= 0)
		kill(phil);
}

int	remain_live(t_philo2 *phil)
{
	long			n;
	long			timing;
	struct timeval	now;

	gettimeofday(&now, NULL);
	n = now.tv_sec * 1000 + now.tv_usec / 1000;
	timing = n - phil->last_meal;
	if (phil->data->kill_all == 1)
		return(1);
	if (phil->remain <= 0)
		return(1);
	return(0);
}