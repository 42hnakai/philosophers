/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:24:06 by hnakai            #+#    #+#             */
/*   Updated: 2023/10/01 20:22:06 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_starttime_us(void)
{
	struct timeval	time;
	long			starttime;

	gettimeofday(&time, NULL);
	starttime = time.tv_sec * 1000000 + (long)time.tv_usec;
	return (starttime);
}

long	get_nowtime_us(void)
{
	struct timeval	nowtime;

	gettimeofday(&nowtime, NULL);
	return (nowtime.tv_sec * (long)1000000 + (long)nowtime.tv_usec);
}

void	my_usleep(long us)
{
	long	starttime_us;
	long	nowtime_us;
	int		i;

	i = 1;
	starttime_us = get_nowtime_us();
	while (1)
	{
		nowtime_us = get_nowtime_us();
		if (nowtime_us - starttime_us >= us)
			return ;
		else
			usleep((us - (nowtime_us - starttime_us)) / 2);
	}
}

long	get_runtime(long starttime_us)
{
	long	runtime;

	runtime = (get_nowtime_us() - starttime_us) / (long)1000;
	return (runtime);
}

void	wait_for_start(long starttime_us)
{
	long	nowtime_us;

	while (1)
	{
		nowtime_us = get_nowtime_us();
		if (nowtime_us >= starttime_us)
			return ;
		else
			my_usleep(((starttime_us - nowtime_us) / (long)2));
	}
}
