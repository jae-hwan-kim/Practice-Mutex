#include "../include/philo.h"

long	time_diff(int last, long curr)
{
	return (curr - last);
}

long	ft_usleep(long time)
{
	long	curr;

	curr = get_time();
	while (time_diff(curr, get_time()) < time)
		usleep(1000);
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	display(t_node *program, t_philo *philo, char *event)
{
	long	current_time;

	current_time = get_time();
	time_diff(program->data->time, current_time);
	program->data->time = current_time;
	printf("philo[%d] %s\n", philo->id, event);
}

void	philo_take_fork(t_node *program, t_philo *philo)
{
	pthread_mutex_lock(philo->m_fork1);
	pthread_mutex_lock(philo->m_fork2);
	pthread_mutex_lock(philo->m_display);
	display(program, philo, FORK);
	display(program, philo, FORK);
	pthread_mutex_unlock(philo->m_display);
}

// void	philo_eat(t_node *program, t_philo *philo)
// {
// 	pthread_mutex_lock(program->philo->m_display);
// 	display(program, philo, EVENT_EAT);
// 	philo->last_meal = get_time(program->data->t_start_usec, program->data->t_start_sec);
// 	pthread_mutex_unlock(program->philo->m_display);
// 	usleep(program->data->t_eat * ONE_MILLISEC);
// 	pthread_mutex_unlock(philo->m_fork1);
// 	pthread_mutex_unlock(philo->m_fork2);
// }

// void	philo_sleep(t_node *program, t_philo *philo)
// {
// 	pthread_mutex_lock(program->philo->m_display);
// 	display(program, philo, EVENT_SLEEP);
// 	pthread_mutex_unlock(program->philo->m_display);
// 	usleep(program->data->t_sleep * ONE_MILLISEC);
// }

// void	philo_think(t_node *program, t_philo *philo)
// {
// 	pthread_mutex_lock(program->philo->m_display);
// 	display(program, philo, EVENT_THINK);
// 	pthread_mutex_unlock(program->philo->m_display);
// }
