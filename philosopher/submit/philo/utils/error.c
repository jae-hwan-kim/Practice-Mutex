/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:53:12 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/08 08:47:10 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_usage(void)
{
	printf("%sUsage : ./philo ", YEL);
	printf("[number_of_philosopher] ");
	printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
	printf("[number_of_time_each_philosophers_must_eat]\n%s", COLOR_RESET);
}
