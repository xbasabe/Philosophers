/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:37:54 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/23 13:14:08 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_threads( pthread_mutex_t	*forks, t_philo2 philo)
{
	int			created;
	pthread_t	*phil_id;
	t_philo2	*philias;

	phil_id = (pthread_t *)malloc(sizeof(pthread_t) * philo.philos);
	philias = (t_philo2 *)malloc(sizeof(t_philo2) * philo.philos);
	created = -1;
	while (++created < philo.philos)
	{
		if (created % 2 != 0)
			usleep(100);
		init_philo(philo, &philias[created]);
		philias[created].forks = forks;
		philias[created].philo_num = created + 1;
		acces_fork(&philias[created]);
		pthread_create(&phil_id[created], NULL, &philoing, &philias[created]);
	}
	created = -1;
	while (++created < philo.philos)
		pthread_join(phil_id[created], NULL);
	created = -1;
	while (++created < philo.philos)
	{
		free(phil_id[created]);
		pthread_mutex_destroy(&philias[created].forks[philias[created].l_fork]);
		//free(philias[created].forks);
	}
	free(forks);
	free(phil_id);
	free(philias);
}

void	acces_fork(t_philo2 *philo)
{
	int	index;

	index = philo->philo_num;
	if (philo->philo_num < philo->philos)
	{
		philo->r_fork = index;
		philo->l_fork = (index - 1);
	}
	if (philo->philo_num == philo->philos)
	{
		philo->l_fork = index - 1;
		philo->r_fork = 0;
	}
}
