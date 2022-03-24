/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:52:25 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/22 19:16:40 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_philo2		philo;

	if (argc == 6)
		printf("meals introducido\n");
	forks = malloc(sizeof(pthread_mutex_t) * atoi(argv[1]));
	init_mutex(forks, atoi(argv[1]));
	init_struct(&philo, argv);
	creat_threads(forks, philo);
	return (0);
}
