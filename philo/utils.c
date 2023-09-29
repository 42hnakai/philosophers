/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:04:57 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 04:04:03 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_philo_info(t_philo_info *philo_info, char *argv[])
{
	philo_info->num = philo_ft_atoi(argv[1]);
	philo_info->dietime = philo_ft_atoi(argv[2]);
	philo_info->eattime = philo_ft_atoi(argv[3]);
	philo_info->sleeptime = philo_ft_atoi(argv[4]);
	if (argv[5] == NULL)
		philo_info->eatcount = INT_MAX;
	else
		philo_info->eatcount = philo_ft_atoi(argv[5]);
}

void	set_id(t_info *info, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		info[i].id = i;
		i++;
	}
}

void	set_atecount(t_info *info, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		*info[i].atecount = 0;
		i++;
	}
}

void	set_last_eattime(t_info *info, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		*(info[i].last_eattime) = 0;
		i++;
	}
}

void	wait_for_start(long starttime)
{
	while (1)
	{
		if (get_runtime(starttime) == 0)
			return ;
		else
			usleep(-get_runtime(starttime)/2);
	}
}