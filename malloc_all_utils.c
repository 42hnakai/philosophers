/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_all_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:13:34 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 01:13:53 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_t(pthread_t **t, int philo_num)
{
	*t = (pthread_t *)malloc(sizeof(pthread_t) * (philo_num + 1));
	if (*t == NULL)
		exit(1);
}

