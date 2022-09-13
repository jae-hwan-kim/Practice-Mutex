/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:48:02 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/08 08:46:42 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static size_t	longer_strlen(char *str1, char *str2)
{
	size_t	str1_len;
	size_t	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	if (str1_len <= str2_len)
		return (str2_len);
	return (str1_len);
}

int	is_same_string(char *str1, char *str2)
{
	size_t	size;

	if (!str1 || !str2)
		return (0);
	size = longer_strlen(str1, str2);
	if (!ft_strncmp(str1, str2, size))
		return (1);
	return (0);
}

int	is_info_valid(t_info *info)
{
	if (info->n_philo == -1 || info->n_philo == 0
		|| info->time_die == -1 || info->time_die == 0
		|| info->time_eat == -1 || info->time_eat == 0
		|| info->time_sleep == -1 || info->time_sleep == 0
		|| info->start_time == -1 || info->start_time == 0
		|| info->must_eat == 0
	)
	{
		printf("%sWarning : Please input positive number (more than 1)\n%s",
			YEL, COLOR_RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	is_argu_valid(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
