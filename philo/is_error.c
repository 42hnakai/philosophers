/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:33:26 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 18:43:13 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_invalid_argc(int argc)
{
	if (!(argc == 5 || argc == 6))
		return (true);
	else
		return (false);
}

bool	is_invalid_philo_info(char *argv[])
{
	if (is_invalid_philo_num(argv[1]) == true)
		return (true);
	else if (is_invalid_philo_dietime(argv[2]) == true)
		return (true);
	else if (is_invalid_philo_eattime(argv[3]) == true)
		return (true);
	else if (is_invalid_philo_sleeptime(argv[4]) == true)
		return (true);
	else if (is_invalid_philo_eatcount(argv[5]) == true)
		return (true);
	else
		return (false);
}

bool	is_error(int argc, char *argv[])
{
	if (is_invalid_argc(argc) == true)
		return (true);
	else if (is_invalid_philo_info(argv) == true)
		return (true);
	else
		return (false);
}
