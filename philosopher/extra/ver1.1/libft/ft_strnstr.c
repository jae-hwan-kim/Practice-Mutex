/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:48:41 by jaekim            #+#    #+#             */
/*   Updated: 2021/12/10 18:46:03 by kimjaehwa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	if (*src == 0)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + n] == src[n] && i + n < len)
		{
			if (src[n + 1] == '\0')
				return ((char *)&str[i]);
			n++;
		}
		i++;
	}
	return (0);
}
