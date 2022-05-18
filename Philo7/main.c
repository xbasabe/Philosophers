/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:52:25 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/05/17 13:24:30 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_comon			data;

	if (argc == 2)
		printf("datos introducidos entre comillas\n");//hacer split
	data.kill_all = 0;
	pthread_mutex_init(&data.dead, NULL);
	pthread_mutex_init(&data.print, NULL);
	forks = malloc(sizeof(pthread_mutex_t) * atoi(argv[1]));
	init_mutex(forks, atoi(argv[1]));
	init_struct(&data, argv);
	creat_threads(forks, data);
	return (0);
}
