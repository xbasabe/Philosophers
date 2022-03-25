/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:01:06 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 13:17:15 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_comon *data, char **argv)
{
	struct timeval	starting;

	data->philos = atoi(argv[1]);
	data->die = atoi(argv[2]);
	data->eat = atoi(argv[3]);
	data->sleep = atoi(argv[4]);
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
/*
void	init_philo(t_philo2 phil, t_philo2 *philias)
{
	philias->philos = phil.philos;
	philias->die = phil.die;
	philias->eat = phil.eat;
	philias->sleep = phil.sleep;
	philias->eaten = phil.eaten;
	philias->start = phil.start;
	philias->remain = phil.remain;
	philias->data = phil.data;
}
*/
