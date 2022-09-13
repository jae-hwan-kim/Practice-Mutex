/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimjaehwan <kimjaehwan@student.42seou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:19:24 by kimjaehwa         #+#    #+#             */
/*   Updated: 2021/12/11 10:23:10 by kimjaehwa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_putnum(int n, size_t i, size_t len, char *result)
{
	while (i < len--)
	{
		if (n < 0)
		{
			result[len] = '0' + (n % 10) * (-1);
			n = n / 10;
		}
		else
		{
			result[len] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (result);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	len = check_len(n);
	result = (char *)malloc(len + 1);
	if (result == 0)
		return (0);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		i = 1;
	}
	return (ft_putnum(n, i, len, result));
}
