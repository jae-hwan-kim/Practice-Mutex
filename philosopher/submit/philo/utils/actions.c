/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:53:57 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:52:29 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	time_to_think(t_philo *philo)
{
	if (!check_is_running(philo) || check_dead_flag(philo))
		return (FAILURE);
	display_state(philo, THINK);
	return (SUCCESS);
}

int	time_to_sleep(t_philo *philo)
{
	if (!check_is_running(philo) || check_dead_flag(philo))
		return (FAILURE);
	display_state(philo, SLEEP);
	ft_usleep(philo->info->time_sleep);
	return (SUCCESS);
}

int	have_a_meal(t_philo *philo)
{
	if (!check_is_running(philo) || check_dead_flag(philo))
	{
		pthread_mutex_unlock(&philo->info->mutex_forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->info->mutex_forks[philo->right_fork]);
		return (FAILURE);
	}
	display_state(philo, EAT);
	pthread_mutex_lock(&philo->info->mutex_time_stamp);
	philo->last_eat_time = timestamp(philo->info->start_time, get_time());
	pthread_mutex_unlock(&philo->info->mutex_time_stamp);
	ft_usleep(philo->info->time_eat);
	pthread_mutex_lock(&philo->info->mutex_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->info->mutex_eat_count);
	if (check_finish_eat_count(philo))
		return (FAILURE);
	pthread_mutex_unlock(&(philo->info->mutex_forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo->info->mutex_forks[philo->left_fork]));
	return (SUCCESS);
}

int	take_left_fork(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
		return (FAILURE);
	if (!check_is_running(philo) || check_dead_flag(philo))
		return (FAILURE);
	pthread_mutex_lock(&philo->info->mutex_forks[philo->left_fork]);
	pthread_mutex_lock(&philo->info->mutex_forks[philo->right_fork]);
	display_state(philo, LEFT_FORK);
	return (SUCCESS);
}

int	take_right_fork(t_philo *philo)
{
	if (!check_is_running(philo) || check_dead_flag(philo))
	{
		pthread_mutex_unlock(&(philo->info->mutex_forks[philo->right_fork]));
		pthread_mutex_unlock(&(philo->info->mutex_forks[philo->left_fork]));
		return (FAILURE);
	}
	display_state(philo, RIGHT_FORK);
	return (SUCCESS);
}
