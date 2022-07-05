/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:37:54 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/06/07 11:40:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_threads( pthread_mutex_t	*forks, t_comon data)
{
	int			created;
	pthread_t	*phil_id;
	t_philo2	*philias;
	pthread_t	checker;

	phil_id = (pthread_t *)malloc(sizeof(pthread_t) * data.philos);
	philias = (t_philo2 *)malloc(sizeof(t_philo2) * data.philos);
	created = -1;
	while (++created < data.philos)
	{
		if (created % 2 != 0)
			usleep(100);
		philias[created].philo_num = created + 1;
		philias[created].data = &data;
		philias[created].data->forks = forks;
		philias[created].eaten = philias[created].data->meals;
		acces_fork(&philias[created]);
		pthread_create(&phil_id[created], NULL, &philoing, &philias[created]);
	}
	pthread_create(&checker, NULL, &remain_live, &data);
	created = -1;
	while (++created < data.philos)
		pthread_join(phil_id[created], NULL);
	pthread_join(checker, NULL);
	free(forks);
	free(phil_id);
	free(philias->data->remain);
	free(philias);
}

void	acces_fork(t_philo2 *philo)
{
	int	index;

	index = philo->philo_num;
	if (philo->philo_num < philo->data->philos)
	{
		philo->r_fork = index;
		philo->l_fork = (index - 1);
	}
	if (philo->philo_num == philo->data->philos)
	{
		philo->l_fork = index - 1;
		philo->r_fork = 0;
	}
}

void	unlock_fork(t_comon *gen, int p_num)
{
	int	index;

	index = p_num;
	if (p_num < gen->philos)
	{
		pthread_mutex_unlock(&gen->forks[index]);
		pthread_mutex_unlock(&gen->forks[index - 1]);
	}
	if (p_num == gen->philos)
	{
		if (p_num != 1)
			pthread_mutex_unlock(&gen->forks[index - 1]);
		pthread_mutex_unlock(&gen->forks[0]);
	}
}
