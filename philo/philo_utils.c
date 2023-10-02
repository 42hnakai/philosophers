/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 04:04:40 by hnakai            #+#    #+#             */
/*   Updated: 2023/10/02 16:51:30 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_data *data, pthread_t *t, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_create(&t[i], NULL, routine, &data[i]) != 0)
			exit(1);
		i++;
	}
	if (pthread_create(&t[philo_num], NULL, check_death, data) != 0)
		exit(1);
}

void	join_threads(pthread_t *t, int philo_num)
{
	int	i;

	i = 0;
	if (pthread_join(t[philo_num], NULL) != 0)
		exit(1);
	while (i < philo_num)
	{
		if (pthread_join(t[i], NULL) != 0)
			exit(1);
		i++;
	}
}

void	destory_mutexes(t_data *data, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_destroy(&data[i].philo_mutex) != 0)
			exit(1);
		i++;
	}
	if (pthread_mutex_destroy(&data->share_data->share_mutex) != 0)
		exit(1);
	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_destroy(&data->share_data->fork_status[i]) != 0)
			exit(1);
		i++;
	}
}

void	free_all(t_data *data, pthread_t *t)
{
	int	i;

	i = 0;
	free((void *)data->share_data->fork_status);
	free((void *)data->share_data);
	free((void *)data);
	free((void *)t);
}
