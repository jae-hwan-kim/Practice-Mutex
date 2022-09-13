/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:50:48 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/08 08:27:59 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_philo_live(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_time_stamp);
	if ((get_time() - philo->info->start_time - philo->last_eat_time)
		>= philo->info->time_die)
	{
		pthread_mutex_unlock(&philo->info->mutex_time_stamp);
		if (check_dead_flag(philo))
			return (FAILURE);
		pthread_mutex_lock(&philo->info->mutex_dead);
		philo->info->dead = true;
		pthread_mutex_unlock(&philo->info->mutex_dead);
		display_state(philo, DEAD);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->info->mutex_time_stamp);
	return (SUCCESS);
}

int	check_philo_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mutex_eat_count);
	if (philo->info->must_eat == philo->eat_count)
	{
		pthread_mutex_unlock(&philo->info->mutex_eat_count);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&philo->info->mutex_eat_count);
	return (FAILURE);
}

int	check_philos_finish(t_philo *philo)
{
	if (!check_is_running(philo) || check_dead_flag(philo))
		return (FAILURE);
	pthread_mutex_lock(&philo->info->mutex_is_running);
	pthread_mutex_lock(&philo->info->mutex_eat_count);
	if (philo->info->finish_count == philo->info->n_philo)
	{
		philo->info->is_running = false;
		pthread_mutex_unlock(&philo->info->mutex_eat_count);
		pthread_mutex_unlock(&philo->info->mutex_is_running);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&philo->info->mutex_eat_count);
	pthread_mutex_unlock(&philo->info->mutex_is_running);
	return (FAILURE);
}
