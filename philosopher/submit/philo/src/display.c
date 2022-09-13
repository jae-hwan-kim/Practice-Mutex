/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:45:33 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:22:21 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	display_done(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->info->mutex_is_running);
	pthread_mutex_lock(&philo->info->mutex_eat_count);
	if (philo->info->finish_count == philo->info->n_philo
		&& philo->info->done == false)
	{
		philo->info->done = true;
		printf("%s\n", state);
		pthread_mutex_unlock(&philo->info->mutex_eat_count);
		pthread_mutex_unlock(&philo->info->mutex_is_running);
	}
	pthread_mutex_unlock(&philo->info->mutex_eat_count);
	pthread_mutex_unlock(&philo->info->mutex_is_running);
}

int	display_state(t_philo *philo, char *state)
{
	if (!check_is_running(philo))
		return (FAILURE);
	pthread_mutex_lock(&philo->info->mutex_display);
	pthread_mutex_lock(&philo->info->mutex_time_stamp);
	if (is_same_string(state, DEAD))
	{
		printf("%ld %d %s\n",
			timestamp(philo->info->start_time, get_time()), philo->id, state);
		pthread_mutex_unlock(&philo->info->mutex_time_stamp);
		pthread_mutex_unlock(&philo->info->mutex_display);
		return (FAILURE);
	}
	if (check_dead_flag(philo))
	{
		pthread_mutex_unlock(&philo->info->mutex_time_stamp);
		pthread_mutex_unlock(&philo->info->mutex_display);
		return (FAILURE);
	}
	printf("%ld %d %s\n",
		timestamp(philo->info->start_time, get_time()), philo->id, state);
	pthread_mutex_unlock(&philo->info->mutex_time_stamp);
	pthread_mutex_unlock(&philo->info->mutex_display);
	return (SUCCESS);
}
