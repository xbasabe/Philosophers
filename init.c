/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:01:06 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/23 10:13:05 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo2 *phil, char **argv)
{
	struct timeval	starting;

	phil->philos = atoi(argv[1]);
	phil->die = atoi(argv[2]);
	phil->eat = atoi(argv[3]);
	phil->sleep = atoi(argv[4]);
	phil->meals = atoi(argv[5]);
	gettimeofday(&starting, NULL);
	phil->start = (starting.tv_usec / 1000) + (starting.tv_sec * 1000);
	phil->remain = phil->die;
	printf("Arguments\n");
	printf("remain%ld\n", phil->remain);
	printf("  -philos %d\n  -die %ld\n  -eat %ld\n  -sleep %ld\n  -meals %d\n", phil->philos, phil->die, phil->eat, phil->sleep, phil->meals);
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

void	init_philo(t_philo2 phil, t_philo2 *philias)
{
	philias->philos = phil.philos;
	philias->die = phil.die;
	philias->eat = phil.eat;
	philias->sleep = phil.sleep;
	philias->meals = phil.meals;
	philias->start = phil.start;
	philias->remain = phil.remain;
}
