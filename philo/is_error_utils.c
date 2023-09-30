/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:35:14 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 18:43:25 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_invalid_philo_num(char *argv)
{
	if (philo_ft_atoi(argv) <= 1)
		return (true);
	else
		return (false);
}

bool	is_invalid_philo_dietime(char *argv)
{
	if (philo_ft_atoi(argv) <= 0)
		return (true);
	else
		return (false);
}

bool	is_invalid_philo_eattime(char *argv)
{
	if (philo_ft_atoi(argv) < 0)
		return (true);
	else
		return (false);
}

bool	is_invalid_philo_sleeptime(char *argv)
{
	if (philo_ft_atoi(argv) < 0)
		return (true);
	else
		return (false);
}

bool	is_invalid_philo_eatcount(char *argv)
{
	if (argv == NULL)
		return (false);
	if (philo_ft_atoi(argv) <= 0)
		return (true);
	else
		return (false);
}
