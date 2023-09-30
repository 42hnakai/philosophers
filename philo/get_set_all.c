/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 04:18:12 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 22:05:21 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_philo_data(t_philo_data *philo_data, char *argv[])
{
	philo_data->num = philo_ft_atoi(argv[1]);
	philo_data->dietime = philo_ft_atoi(argv[2]);
	philo_data->eattime = philo_ft_atoi(argv[3]);
	philo_data->sleeptime = philo_ft_atoi(argv[4]);
	if (argv[5] == NULL)
		philo_data->eatcount = INT_MAX;
	else
		philo_data->eatcount = philo_ft_atoi(argv[5]);
}

void	set_share_data(t_share_data *share_data, char *argv[], int philo_num)
{
	int	i;

	i = 0;
	pthread_mutex_init(&share_data->share_mutex, NULL);
	share_data->dead_flag = ALIVE;
	share_data->starttime = get_starttime() + 1000;
	get_philo_data(&share_data->philo_data, argv);
	while (i < philo_num)
	{
		pthread_mutex_init(&share_data->fork_status[i], NULL);
		i++;
	}
}

void	get_set_all(t_data *data, char *argv[], int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&data[i].philo_mutex, NULL);
		data[i].id = i;
		data[i].atecount = 0;
		data[i].last_eattime = 0;
		i++;
	}
	set_share_data(data->share_data, argv, philo_num);
}
