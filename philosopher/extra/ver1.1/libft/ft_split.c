/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimjaehwan <kimjaehwan@student.42seou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:55:55 by kimjaehwa         #+#    #+#             */
/*   Updated: 2021/12/11 16:46:24 by kimjaehwa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_w_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len);
}

char	*ft_w_make(char *word, char const *s, int n, int w_len)
{
	int		i;

	i = 0;
	while (w_len > 0)
	{
		word[i] = s[n - w_len];
		i++;
		w_len--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split2(char **result, char const *s, char c, int w_len)
{
	int		i;
	int		n;
	int		w_len2;

	i = 0;
	n = 0;
	w_len2 = 0;
	while (s[n] && i < w_len)
	{
		while (s[n] && s[n] == c)
			n++;
		while (s[n] && s[n] != c)
		{
			n++;
			w_len2++;
		}
		result[i] = (char *)malloc(sizeof(char) * (w_len2 + 1));
		if (result == 0)
			return (0);
		ft_w_make(result[i], s, n, w_len2);
		w_len2 = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		w_len;
	char	**result;

	if (s == 0)
		return (0);
	w_len = ft_w_len(s, c);
	result = (char **)malloc(sizeof(char *) * (w_len + 1));
	if (result == 0)
		return (0);
	ft_split2(result, s, c, w_len);
	return (result);
}
