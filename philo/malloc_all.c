/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:07:50 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 16:15:20 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_all(t_data **data, pthread_t **t, int philo_num)
{
	int	i;

	i = 0;
	*data = malloc_data(philo_num);
	(*data)->share_data = malloc_share_data(philo_num);
	while (i < philo_num)
	{
		(*data)[i].share_data = (*data)->share_data;
		i++;
	}
	malloc_t(t, philo_num);
}

t_data	*malloc_data(int philo_num)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * philo_num);
	if (data == NULL)
		exit(1);
	return (data);
}

t_share_data	*malloc_share_data(int philo_num)
{
	t_share_data	*share_data;

	share_data = malloc(sizeof(t_share_data) * 1);
	if (share_data == NULL)
		exit(1);
	share_data->fork_status = malloc_fork_status(philo_num);
	return (share_data);
}

pthread_mutex_t	*malloc_fork_status(int philo_num)
{
	pthread_mutex_t *fork_status;
	fork_status = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo_num);
	if (fork_status == NULL)
		exit(1);
	return (fork_status);
}

void	malloc_t(pthread_t **t, int philo_num)
{
	*t = (pthread_t *)malloc(sizeof(pthread_t) * (philo_num + 1));
	if (*t == NULL)
		exit(1);
}
