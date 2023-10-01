/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:04:57 by hnakai            #+#    #+#             */
/*   Updated: 2023/10/01 18:30:31 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_check(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return (i);
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
			i++;
		else if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
			return (i + 1);
		else
			return (-1);
	}
	return (-1);
}

int	philo_ft_atoi(const char *str)
{
	long	num;
	size_t	i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	if (ft_check(str) == -1)
		return (-1);
	i = ft_check(str);
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (ft_isdigit(str[i + 1]))
	{
		num = (num + sign * (str[i++] - '0')) * 10;
		if (((num <= LONG_MIN / 10) && (str[i] - '0' > LONG_MAX % 10))
			|| (LONG_MIN < num && num < LONG_MIN / 10 && str[i + 1] != '\0'))
			return ((int)(LONG_MIN));
		if (((num / 10 >= LONG_MAX / 10) && (str[i] - '0' > LONG_MAX % 10))
			|| (LONG_MAX / 10 < num && num < LONG_MAX && str[i + 1] != '\0'))
			return ((int)(LONG_MAX));
	}
	num = num + sign * (str[i] - '0');
	return ((int)num);
}

int	philo_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	i = 0;
	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	while (i < n && (us1[i] != '\0' || us2[i] != '\0'))
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
