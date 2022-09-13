/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:51:30 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/07 01:52:00 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	safe_thread_init(pthread_t *thread, void *param, char *type)
{
	if (is_same_string(type, "philo"))
	{
		if (pthread_create(thread, NULL, &action, param))
			return (FAILURE);
	}
	else if (is_same_string(type, "monitor"))
	{
		if (pthread_create(thread, NULL, &action_monitor, param))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	safe_mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		return (FAILURE);
	return (SUCCESS);
}

void	*safe_malloc(size_t size)
{
	void	*allocated_ptr;

	allocated_ptr = malloc(size);
	if (!allocated_ptr)
		return ((void *) FAILURE);
	return (allocated_ptr);
}
