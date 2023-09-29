/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:36 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 01:20:26 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define TAKING_FORK "has taken a fork"
# define DIED "died"

enum				e_philo_status
{
	DEAD,
	ALIVE
};

enum				e_philo_status
{
	SUCCESS,
	FAIL
};

typedef struct s_philo_info
{
	int				num;
	int				dietime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
}					t_philo_info;

typedef struct s_share_data
{
	pthread_mutex_t	*share_lock;
	int				*dead_flag;
	long			starttime;
	pthread_mutex_t	*fork_status;

}					t_share_data;

typedef struct s_info
{
	pthread_mutex_t	*philo_lock;
	unsigned int	id;
	t_philo_info	*philo_info;
	t_share_data	*share_data;
	int				*atecount;
	long			*last_eattime;
}					t_info;

#endif