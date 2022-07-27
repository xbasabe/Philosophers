/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:01:06 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/07/14 10:19:33 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_comon *data, char **argv)
{
	struct timeval	starting;
	int				i;

	data->philos = atoi(argv[1]);
	data->die = atoi(argv[2]);
	data->eat = atoi(argv[3]);
	data->sleep = atoi(argv[4]);
	data->remain = (long *)malloc(sizeof(long) * data->philos);
	data->done = (int *)malloc(sizeof(int) * data->philos);
	i = 0;
	while (i < data->philos)
	{
		data->remain[i] = data->die;
		data->done[i] = 1;
		i++;
	}
	data->meals = -1;
	if (argv[5])
		data->meals = atoi(argv[5]);
	gettimeofday(&starting, NULL);
	data->start = (starting.tv_usec / 1000) + (starting.tv_sec * 1000);
	data->kill_all = 0;
}

void	init_mutex(pthread_mutex_t	*forks, int numb_philos)
{
	int	c;

	c = 0;
	while (c < numb_philos)
	{
		pthread_mutex_init(&forks[c], NULL);
		c++;
	}
}
