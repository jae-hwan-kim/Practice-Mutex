/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:24:31 by jaekim            #+#    #+#             */
/*   Updated: 2021/12/12 12:15:22 by kimjaehwa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s)
		return (0);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == 0)
		return (0);
	while (s[i])
	{
		if (i >= start && i2 < len)
		{
			temp[i2] = s[i];
			i2++;
		}
		i++;
	}
	temp[i2] = '\0';
	return (temp);
}
