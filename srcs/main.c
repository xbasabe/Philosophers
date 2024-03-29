/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:52:25 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/07/14 11:54:45 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_comon			data;

	if (5 > argc || 6 < argc)
		return (1);
	data.kill_all = 0;
	pthread_mutex_init(&data.dead, NULL);
	pthread_mutex_init(&data.print, NULL);
	pthread_mutex_init(&data.updating, NULL);
	forks = malloc(sizeof(pthread_mutex_t) * atoi(argv[1]));
	init_mutex(forks, atoi(argv[1]));
	init_struct(&data, argv);
	creat_threads(forks, data);
	return (0);
}
