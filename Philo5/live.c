/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:08:53 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 13:06:54 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	live_sleep(t_philo2 *phil)
{
	long			count;
	long			s;
	long			n;
	struct timeval	start;
	struct timeval	now;

	count = 0;
	gettimeofday(&start, NULL);
	while (count < phil->data->sleep)
	{
		usleep(100);
		gettimeofday(&now, NULL);
		s = start.tv_sec * 1000 + start.tv_usec / 1000;
		n = now.tv_sec * 1000 + now.tv_usec / 1000;
		count += n - s;
		if (count >= phil->remain)
			kill(phil);
	}
	phil->remain = phil->remain - count;
	return (0);
}

int	live_thinking(t_philo2 *phil)
{
	long			count;
	long			timing;
	struct timeval	start;
	struct timeval	now;

	count = 0;
	while (count < phil->remain)
	{
		gettimeofday(&start, NULL);
		usleep(10);
		gettimeofday(&now, NULL);
		timing = (now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000;
		count += timing;
		if (count >= phil->remain)
			kill(phil);
	}
	return (0);
}

int	live_eating(t_philo2 *phil)
{
	long			count;
	long			s;
	long			n;
	struct timeval	start;
	struct timeval	now;

	count = 0;
	gettimeofday(&start, NULL);
	while (count < phil->data->eat)
	{
		usleep(10);
		gettimeofday(&now, NULL);
		s = start.tv_sec * 1000 + start.tv_usec / 1000;
		n = now.tv_sec * 1000 + now.tv_usec / 1000;
		count += n - s;
		if (count >= phil->remain)
			kill(phil);
	}
	phil->remain = phil->remain - count;
	return (0);

}

