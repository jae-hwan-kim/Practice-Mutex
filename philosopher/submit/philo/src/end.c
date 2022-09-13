/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:43:51 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/07 01:43:54 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	end_thread(t_info *info)
{
	int	index;

	index = 0;
	while (index < info->n_philo)
	{
		if (pthread_join(info->philo[index].tid, NULL))
			return (FAILURE);
		index++;
	}
	return (SUCCESS);
}

int	del_and_free_all(t_info *info)
{
	int	index;

	index = 0;
	while (index < info->n_philo)
	{
		pthread_mutex_destroy(&(info->mutex_forks[index]));
		index++;
	}
	pthread_mutex_destroy(&(info->mutex_display));
	pthread_mutex_destroy(&(info->mutex_eat_count));
	pthread_mutex_destroy(&(info->mutex_time_stamp));
	pthread_mutex_destroy(&(info->mutex_is_running));
	pthread_mutex_destroy(&(info->mutex_dead));
	free(info->mutex_forks);
	free(info->philo);
	return (SUCCESS);
}
