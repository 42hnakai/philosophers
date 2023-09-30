/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnakai <hnakai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:31:36 by hnakai            #+#    #+#             */
/*   Updated: 2023/09/30 21:26:18 by hnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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

enum				e_act_status
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
	t_philo_data	philo_data;
	pthread_mutex_t	*fork_status;

}					t_share_data;

typedef struct s_data
{
	pthread_mutex_t	philo_mutex;
	int				id;
	int				atecount;
	long			last_eattime;
	t_share_data	*share_data;
}					t_data;

//=is_error.c==================================================================
bool				is_error(int argc, char *argv[]);
bool				is_invalid_argc(int argc);
bool				is_invalid_philo_info(char *argv[]);
// is_error_utils.c=============================================================
bool				is_invalid_philo_num(char *argv);
bool				is_invalid_philo_dietime(char *argv);
bool				is_invalid_philo_eattime(char *argv);
bool				is_invalid_philo_sleeptime(char *argv);
bool				is_invalid_philo_eatcount(char *argv);
//=malloc_all.c================================================================
void				malloc_all(t_data **data, pthread_t **t, int philo_num);
t_data				*malloc_data(int philo_num);
t_share_data		*malloc_share_data(int philo_num);
pthread_mutex_t		*malloc_fork_status(int philo_num);
void				malloc_t(pthread_t **t, int philo_num);
//=get_set_all.c===============================================================
void				get_set_all(t_data *data, char *argv[], int philo_num);
void				get_philo_data(t_philo_data *philo_data, char *argv[]);
void				set_share_data(t_share_data *share_data, char *argv[],
						int philo_num);
//=philo_utils.c===============================================================
void				create_threads(t_data *data, pthread_t *t, int philo_num);
void				join_threads(pthread_t *t, int philo_num);
void				destory_mutexes(t_data *data, int philo_num);
void				free_all(t_data *data, pthread_t *t);
void				wait_for_start(long starttime);
//=routine.c===================================================================
void				*routine(void *void_data);
int					philo_eat(t_data *data);
int					philo_sleep(t_data *data);
int					philo_think(t_data *data);
//=routine_utils.c==============================================================
int					take_left_fork(t_data *data);
int					take_right_fork(t_data *data);
void				after_eat(t_data *data);
int					put_philo_act(t_data *data, char *philo_act);
void				my_msleep(long ms);
//=check_death.c===============================================================
void				*check_death(void *void_data);
bool				is_over_eat(t_data *data, int philo_num);
bool				is_over_dietime(t_data *data);
int					check_dead_flag(t_data *data);
void				change_dead_flag(t_data *data);
//=utils.c=====================================================================
int					ft_isdigit(int c);
int					ft_check(const char *str);
int					philo_ft_atoi(const char *str);
long				get_starttime(void);
long				get_runtime(long starttime);

#endif