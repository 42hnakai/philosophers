/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 03:18:56 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 04:54:44 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *void_data)
{
	int		i;
	t_data	*data;

	data = (t_data *)void_data;
	wait_for_start(data->share_data->starttime);
	while (1)
	{
		i = 0;
		while (i < data->share_data->philo_data.num)
		{
			pthread_mutex_lock(&data->share_data->share_mutex);
			if (is_over_dietime(&data[i]) == true)
			{
				put_philo_act(&data[i], DIED);
				change_dead_flag(data);
				return (NULL);
			}
			else if (is_over_eat(data,
									data->share_data->philo_data.num) == true)
			{
				change_dead_flag(data);
				return (NULL);
			}
			pthread_mutex_unlock(&data->share_data->share_mutex);
			i++;
		}
	}
}

bool	is_over_eat(t_data *data, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (data[i].atecount < data->share_data->philo_data.eatcount)
			return (false);
		i++;
	}
	return (true);
}

int	check_dead_flag(t_data *data)
{
	pthread_mutex_lock(&data->share_data->share_mutex);
	if (data->share_data->dead_flag == DEAD)
	{
		pthread_mutex_unlock(&data->share_data->share_mutex);
		return (DEAD);
	}
	else
	{
		pthread_mutex_unlock(&data->share_data->share_mutex);
		return (ALIVE);
	}
}

bool	is_over_dietime(t_data *data)
{
	pthread_mutex_lock(data->lasteat_mutex);
	if (get_runtime(*data->starttime)
		- *data->last_eattime >= data->philo_data->dietime)
	{
		pthread_mutex_unlock(data->lasteat_mutex);
		return (true);
	}
	pthread_mutex_unlock(data->lasteat_mutex);
	return (false);
}

void	change_dead_flag(t_data *data)
{
	data->share_data->dead_flag = DEAD;
}
