/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:16:05 by jaekim            #+#    #+#             */
/*   Updated: 2021/12/28 13:52:09 by kimjaehwa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i_dest;
	size_t	i_str;
	char	*dest;

	if (s1 == 0 || s2 == 0)
		return (0);
	i_dest = 0;
	i_str = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (dest == 0)
		return (0);
	while (i_str < len1)
		dest[i_dest++] = s1[i_str++];
	i_str = 0;
	while (i_str < len2)
		dest[i_dest++] = s2[i_str++];
	dest[i_dest] = '\0';
	return (dest);
}
