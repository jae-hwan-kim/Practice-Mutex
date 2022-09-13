/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:46:57 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:20:08 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*action(void *param)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)param;
	if (philo->id % 2)
		ft_usleep(philo->info->time_eat);
	// 생각하는 상태로 시작한다면, 모니터를 ft_usleep전에 하는게 좋을 듯.
	if (!safe_thread_init(&monitor, philo, MONITOR))
		return ((void *) FAILURE);
	pthread_mutex_lock(&philo->info->mutex_time_stamp);
	philo->last_eat_time = get_time() - philo->info->start_time;
	pthread_mutex_unlock(&philo->info->mutex_time_stamp);
	while (check_is_running(philo))
	{
		if (!take_left_fork(philo) || !take_right_fork(philo)
			|| !have_a_meal(philo) || !time_to_sleep(philo)
			|| !time_to_think(philo))
		{
			display_done(philo, DONE);
			pthread_join(monitor, NULL);
			return ((void *) FAILURE);
		}
		usleep(100);
	}
	pthread_join(monitor, NULL);
	return ((void *) SUCCESS);
}
