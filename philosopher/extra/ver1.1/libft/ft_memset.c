/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:10:53 by jaekim            #+#    #+#             */
/*   Updated: 2021/12/06 13:00:23 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*d_ptr;
	unsigned char	value;

	d_ptr = (char *)b;
	value = (unsigned char)c;
	while (len > 0)
	{
		*d_ptr = c;
		d_ptr++;
		len--;
	}
	return (b);
}
