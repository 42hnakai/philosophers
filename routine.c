/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:16:07 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 01:38:36 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_info *info)
{
	if (put_philo_act(info, EATING) == SUCCESS)
	{
		*info->last_eattime = get_runtime(*info->starttime);
		my_msleep(info->philo_info->eattime);
		*info->atecount = *info->atecount + 1;
	}
	else
		return (FAIL);
}

int	philo_sleep(t_info *info)
{
	if (put_philo_act(info, SLEEPING) == SUCCESS)
	{
		my_msleep(info->philo_info->sleeptime);
		return (SUCCESS);
	}
	else
		return (FAIL);
}

int	philo_think(t_info *info)
{
	if (put_philo_act(info, THINKING) == SUCCESS)
		return (SUCCESS);
	else
		return (FAIL);
}

void	*routine(void *void_info)
{
	t_info *info;

	info = (t_info *)void_info;
	while (true)
	{
		if (get_runtime(*info->starttime) == 0)
			break ;
		usleep(-get_runtime(*info->starttime) / 2);
	}
	if (info->id % 2 != 0)
		usleep(50);
	while (1)
	{
		if (prepare_eat(info) == FAIL)
			return (NULL);
		else if (after_eat(info) == FAIL)
			return (NULL);
		else if (philo_eat(info) == FAIL)
			return (NULL);
		else if (after_eat(info) == FAIL)
			return (NULL);
		else if (philo_sleep(info) == FAIL)
			return (NULL);
		else if (philo_think(info) == FAIL)
			return (NULL);
	}
}