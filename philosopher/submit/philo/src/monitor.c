/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:39:40 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:23:09 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*action_monitor(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (check_is_running(philo))
	{
		if (!check_philo_live(philo))
		{
			pthread_mutex_lock(&philo->info->mutex_is_running);
			philo->info->is_running = false;
			pthread_mutex_unlock(&philo->info->mutex_is_running);
			return ((void *) FAILURE);
		}
		if (check_philos_finish(philo))
			return ((void *) FAILURE);
		if (check_philo_finish(philo))
		{
			while (check_is_running(philo))
				if (check_philos_finish(philo))
					return ((void *) FAILURE);
		}
		usleep(250);
	}
	return ((void *) SUCCESS);
}
