/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 05:00:02 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 05:13:13 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_fork(t_data *data)
{
	if (data->id + 1 == data->share_data->philo_data.num)
	{
		pthread_mutex_lock(&data->share_data->fork_status[data->id]);
		if (put_philo_act(data, TAKING_FORK) == FAIL)
		{
			pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
			return (FAIL);
		}
	}
	else
	{
		pthread_mutex_lock(&data->share_data->fork_status[data->id]);
		if (put_philo_act(data, TAKING_FORK) == FAIL)
		{
			pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

void	after_eat(t_data *data)
{
	if (data->id + 1 == data->share_data->philo_data.num)
	{
		pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
		pthread_mutex_unlock(&data->share_data->fork_status[0]);
	}
	else
	{
		pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
		pthread_mutex_unlock(&data->share_data->fork_status[data->id + 1]);
	}
}