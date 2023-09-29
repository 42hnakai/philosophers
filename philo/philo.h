/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:36 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 05:04:49 by hnakai           ###   ########.fr       */
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

typedef struct s_philo_data
{
	int				num;
	int				dietime;
	int				eattime;
	int				sleeptime;
	int				eatcount;
}					t_philo_data;

typedef struct s_share_data
{
	pthread_mutex_t	share_mutex;
	int				dead_flag;
	long			starttime;
	t_philo_info	philo_data;
	pthread_mutex_t	*fork_status;

}					t_share_data;

typedef struct s_data
{
	pthread_mutex_t	philo_mutex;
	unsigned int	id;
	int				atecount;
	long			last_eattime;
	t_share_data	*share_data;
}					t_data;
//=check_death.c===============================================================
void				*check_death(void *void_data);
bool				is_over_eat(t_data *data, int philo_num);
bool				is_over_dietime(t_data *data);
int					check_dead_flag(t_data *data);
//=philo.c=====================================================================
//=philo_utils.c===============================================================
void				create_threads(t_data *data, pthread_t *t, int philo_num);
void				join_threads(pthread_t *t, int philo_num);
void				destory_mutexes(t_data *data, int philo_num);
void				free_all(t_data *data, pthread_t *t, int philo_num);
//=routine.c===================================================================
void				*routine(void *void_data);
int					philo_eat(t_data *data);
int					philo_sleep(t_data *data);
int					philo_think(t_data *data);
//routine_utils.c==============================================================
void				prepare_eat(t_data *data);
void				after_eat(t_data *data);

#endif