/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:43:18 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/11 19:22:51 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_thread(t_info *info)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	info->start_time = get_time();
	while (index < info->n_philo)
	{
		if (!safe_thread_init(&(info->philo[index].tid),
				&(info->philo[index]), PHILO))
		{
			while (flag < index)
			{
				pthread_join(info->philo[flag].tid, NULL);
				del_and_free_all(info);
			}
			return (FAILURE);
		}
		index++;
		usleep(10);
	}
	return (SUCCESS);
}

int	init_mutex(t_info *info)
{
	int	index;

	index = 0;
	info->mutex_forks = safe_malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->mutex_forks)
		return (FAILURE);
	while (index < info->n_philo)
	{
		if (!safe_mutex_init(&(info->mutex_forks[index])))
			return (FAILURE);
		index++;
	}
	if (!safe_mutex_init(&(info->mutex_time_stamp))
		|| !safe_mutex_init(&(info->mutex_is_running))
		|| !safe_mutex_init(&(info->mutex_display))
		|| !safe_mutex_init(&(info->mutex_eat_count))
		|| !safe_mutex_init(&(info->mutex_dead))
	)
		return (FAILURE);
	return (SUCCESS);
}

int	init_philo(t_info *info)
{
	int	index;

	index = 0;
	info->philo = safe_malloc(sizeof(t_philo) * info->n_philo);
	if (!info->philo)
		return (FAILURE);
	while (index < info->n_philo)
	{
		info->philo[index].id = index;
		info->philo[index].left_fork = index;
		info->philo[index].right_fork = (index + 1) % info->n_philo;
		info->philo[index].eat_count = 0;
		info->philo[index].last_eat_time = 0;
		info->philo[index].tid = 0;
		info->philo[index].info = info;
		index += 1;
	}
	return (SUCCESS);
}

int	init_info(int ac, char **av, t_info *info)
{
	if (ac < 5 || ac > 6 || !is_argu_valid(av))
	{
		print_usage();
		return (FAILURE);
	}
	info->n_philo = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->start_time = get_time();
	info->done = false;
	info->dead = false;
	info->is_running = true;
	info->finish_count = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	if (!is_info_valid(info))
		return (FAILURE);
	return (SUCCESS);
}
