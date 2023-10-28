/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 05:00:02 by hnakai            #+#    #+#             */
/*   Updated: 2023/10/28 19:59:43 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_fork(t_data *data)
{
	pthread_mutex_lock(&data->share_data->fork_status[data->id]);
	if (put_philo_act(data, TAKING_FORK) == FAIL
		|| data->share_data->philo_data.num == 1)
	{
		pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
		return (FAIL);
	}
	return (SUCCESS);
}

int	take_right_fork(t_data *data)
{
	if (data->id + 1 == data->share_data->philo_data.num)
	{
		pthread_mutex_lock(&data->share_data->fork_status[0]);
		if (put_philo_act(data, TAKING_FORK) == FAIL)
		{
			pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
			pthread_mutex_unlock(&data->share_data->fork_status[0]);
			return (FAIL);
		}
	}
	else
	{
		pthread_mutex_lock(&data->share_data->fork_status[data->id + 1]);
		if (put_philo_act(data, TAKING_FORK) == FAIL)
		{
			pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
			pthread_mutex_unlock(&data->share_data->fork_status[data->id + 1]);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

void	after_eat(t_data *data)
{
	if (data->id + 1 == data->share_data->philo_data.num)
	{
		pthread_mutex_unlock(&data->share_data->fork_status[0]);
		pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
	}
	else
	{
		pthread_mutex_unlock(&data->share_data->fork_status[data->id + 1]);
		pthread_mutex_unlock(&data->share_data->fork_status[data->id]);
	}
}

int	put_philo_act(t_data *data, char *philo_act)
{
	if (philo_ft_strncmp(DIED, philo_act, 4) == 0)
	{
		pthread_mutex_lock(&data->share_data->share_mutex);
		printf("%ld %d %s\n", get_runtime(data->share_data->starttime), data->id
			+ 1, philo_act);
		pthread_mutex_unlock(&data->share_data->share_mutex);
		return (SUCCESS);
	}
	pthread_mutex_lock(&data->share_data->share_mutex);
	if (check_dead_flag(data) == DEAD)
	{
		pthread_mutex_unlock(&data->share_data->share_mutex);
		return (FAIL);
	}
	printf("%ld %d %s\n", get_runtime(data->share_data->starttime), data->id
		+ 1, philo_act);
	pthread_mutex_unlock(&data->share_data->share_mutex);
	return (SUCCESS);
}
