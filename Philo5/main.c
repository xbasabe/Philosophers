/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:52:25 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/03/25 12:58:36 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_comon			data;

	if (argc == 6)
		printf("meals introducido\n");
	data.kill_all = 0;
	forks = malloc(sizeof(pthread_mutex_t) * atoi(argv[1]));
	init_mutex(forks, atoi(argv[1]));
	init_struct(&data, argv);
	creat_threads(forks, data);
	return (0);
}
