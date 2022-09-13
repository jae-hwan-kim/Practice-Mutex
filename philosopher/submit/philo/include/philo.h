/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:32:27 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/08 08:47:33 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*	libraries	*/
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>

/*	thread	*/
# define PHILO "philo"
# define MONITOR "monitor"

/*	color	*/
# define YEL "\e[0;33m"
# define COLOR_RESET "\e[0m"

/*	messages	*/
# define LEFT_FORK	"has taken a left fork"
# define RIGHT_FORK	"has taken a right fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"is dead"
# define DONE	"DONE"

enum e_boolean {
	FAILURE = 0,
	SUCCESS = 1,
};

/*	structures	*/
typedef struct s_info	t_info;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long		last_eat_time;
	pthread_t	tid;
	t_info		*info;
}	t_philo;

typedef struct s_info
{
	int				n_philo;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				finish_count;
	long			time_die;
	long			start_time;
	bool			done;
	bool			dead;
	bool			is_running;
	t_philo			*philo;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_display;
	pthread_mutex_t	mutex_eat_count;
	pthread_mutex_t	mutex_time_stamp;
	pthread_mutex_t	mutex_is_running;
	pthread_mutex_t	mutex_dead;
}	t_info;

/***	src	***/
/*	action.c	*/
void	*action(void *philo);

/*	display.c	*/
int		display_state(t_philo *philo, char *state);
void	display_done(t_philo *philo, char *state);

/*	end.c	*/
int		del_and_free_all(t_info *info);
int		end_thread(t_info *info);

/*	init.c	*/
int		init_info(int ac, char **av, t_info *info);
int		init_mutex(t_info *info);
int		init_philo(t_info *info);
int		init_thread(t_info *info);

/*	monitor.c	*/
void	*action_monitor(void *info);

/*	time.c	*/
long	get_time(void);
long	timestamp(long start_time, long current_time);
int		ft_usleep(long time);

/***	utils	***/
/*	action_utils.c	*/
int		take_left_fork(t_philo *philo);
int		take_right_fork(t_philo *philo);
int		have_a_meal(t_philo *philo);
int		time_to_sleep(t_philo *philo);
int		time_to_think(t_philo *philo);

/*	check_utils.c	*/
int		check_is_running(t_philo *philo);
int		check_dead_flag(t_philo *philo);
int		check_philo_live(t_philo *philo);
int		check_philo_finish(t_philo *philo);
int		check_philos_finish(t_philo *philo);
int		check_finish_eat_count(t_philo *philo);

/*	error.c	*/
void	print_usage(void);

/*	is_utils.c	*/
int		is_info_valid(t_info *info);
int		is_argu_valid(char **av);
int		is_same_string(char *str1, char *str2);

/*	safe_utils.c	*/
void	*safe_malloc(size_t size);
int		safe_mutex_init(pthread_mutex_t *mutex);
int		safe_thread_init(pthread_t *thread, void *param, char *type);
int		safe_mutex_lock(pthread_mutex_t *mutex);

/*	etc	*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif
