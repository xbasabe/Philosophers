/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:24:35 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 13:39:14 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timer(long wait)
{
	long			count;
	long			init;
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	count = 0;
	init = (start.tv_usec / 1000) + (start.tv_sec * 1000);
	while (count < wait)
	{
		gettimeofday(&now, NULL);
		usleep(10);
		count = (now.tv_usec / 1000) + (now.tv_sec * 1000) - init;
	}
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
	if (timing >= phil->remain)
		kill(phil);
}
