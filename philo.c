/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:29:58 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 00:40:23 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info *info;
	pthread_t *t;
	int philo_num;

	if (is_error(argc, argv) == true)
		return (0);
	philo_num = philo_ft_atoi(argv[1]);
	malloc_all(&info, &t, philo_num);
	get_set_all(info, argv);
	create_threads(t, info, philo_num);
	join_mutexes();
	destory_mutexes(info);
	free_all(info, t, philo_num);
	return (0);
}