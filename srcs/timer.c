/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:24:35 by xbasabe-          #+#    #+#             */
/*   Updated: 2022/06/14 10:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timer(long wait, t_philo2 *phil)
{
	long			count;
	long			init;
	struct timeval	start;
	struct timeval	now;
//	int				p_num;

	gettimeofday(&start, NULL);
	count = 0;
	init = (start.tv_usec / 1000) + (start.tv_sec * 1000);
	while (count < wait)
	{
		gettimeofday(&now, NULL);
		usleep(100);
		count = (now.tv_usec / 1000) + (now.tv_sec * 1000) - init;
		if (phil->data->kill_all == 1)
			return(2);
	}
	return (0);
}

void	*remain_live(void *data)
{
	t_comon		*general;
	int			p_num;

	general = (t_comon *)data;

	while(1)
	{
		usleep(100);
		p_num = update(general);
		if (p_num != 0)
			break ;
	}
	kill(general, p_num);
	return(NULL);
}

int	all_alive(t_philo2 *phil)
{
	int	p_num;
	
	if (phil->data->kill_all == 1 )
		return(2);
	p_num = update(phil->data);
	if (p_num != 0)
	{
		kill(phil->data, p_num);
		return(1);
	}
	return(0);
}

int	update(t_comon *phil)
{
	long			now;
	long			wait;
	struct timeval	n;
	int				i;
	
	gettimeofday(&n, NULL);
	now = (n.tv_usec / 1000) + (n.tv_sec * 1000);
	wait = now - phil->last_check;
	i = 0;
	while (i < phil->philos)
	{
		phil->remain[i] -= wait;
		if(phil->remain[i] <= 0)
			return(i + 1);
		i++;
	}
	phil->last_check = now;
	return(0);
}
