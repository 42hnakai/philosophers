/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:07:50 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 01:13:25 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_all(t_info **info, pthread_t **t, int philo_num)
{
	int i;

	i = 0;
	*info = malloc_info(philo_num);
	(*info)->share_data = malloc_share_data();
	while (i < philo_num)
	{
		(*info)[i].philo_info = (*info)->philo_info;
		(*info)[i].share_data = (*info)->share_data;
		i++;
	}
	malloc_t(t, philo_num);
}

