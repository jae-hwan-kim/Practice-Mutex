/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:36:32 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/07 01:36:34 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (false
		|| !init_info(ac, av, &info)
		|| !init_philo(&info)
		|| !init_mutex(&info)
		|| !init_thread(&info)
		|| !end_thread(&info)
		|| !del_and_free_all(&info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
