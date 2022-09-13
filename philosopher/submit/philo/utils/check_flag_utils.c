/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:50:48 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:52:09 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_finish_eat_count(t_philo *philo)
{
	if (philo->eat_count == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->mutex_eat_count);
		philo->info->finish_count += 1;
		pthread_mutex_unlock(&philo->info->mutex_eat_count);
		pthread_mutex_unlock(&(philo->info->mutex_forks[philo->right_fork]));
		pthread_mutex_unlock(&(philo->info->mutex_forks[philo->left_fork]));
		ft_usleep(10);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_dead);
	if (philo->info->dead)
	{
		pthread_mutex_unlock(&philo->info->mutex_dead);
		return (true);
	}
	pthread_mutex_unlock(&philo->info->mutex_dead);
	return (false);
}

int	check_is_running(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->mutex_is_running));
	if (philo->info->is_running)
	{
		pthread_mutex_unlock(&(philo->info->mutex_is_running));
		return (true);
	}
	pthread_mutex_unlock(&(philo->info->mutex_is_running));
	return (false);
}
