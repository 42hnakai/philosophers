/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:16:07 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 05:11:34 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_data *data)
{
	if (put_philo_act(data, EATING) == SUCCESS)
	{
		pthread_mutex_lock(&data->philo_mutex);
		data->last_eattime = get_runtime(data->share_data->starttime);
		pthread_mutex_unlock(&data->philo_mutex);
		my_msleep(data->share_data->philo_data.eattime);
		pthread_mutex_lock(&data->philo_mutex);
		data->atecount = data->atecount + 1;
		pthread_mutex_unlock(&data->philo_mutex);
	}
	else
		return (FAIL);
}

int	philo_sleep(t_data *data)
{
	if (put_philo_act(data, SLEEPING) == SUCCESS)
	{
		my_msleep(data->share_data->philo_data.sleeptime);
		return (SUCCESS);
	}
	else
		return (FAIL);
}

int	philo_think(t_data *data)
{
	if (put_philo_act(data, THINKING) == SUCCESS)
		return (SUCCESS);
	else
		return (FAIL);
}

void	*routine(void *void_data)
{
	t_data *data;

	data = (t_data *)void_data;
	wait_for_start(data->share_data->starttime);
	if (data->id % 2 != 0)
		usleep(50);
	while (1)
	{
		if (take_left_fork(data) == FAIL)
			return (NULL);
		else if (take_right_fork(data) == FAIL)
			return (NULL);
		else if (philo_eat(data) == FAIL)
			return (NULL);
		else if (after_eat(data) == FAIL)
			return (NULL);
		else if (philo_sleep(data) == FAIL)
			return (NULL);
		else if (philo_think(data) == FAIL)
			return (NULL);
	}
}