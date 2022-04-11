/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:56:56 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/02 16:57:06 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	fill_ret(char *ret, const char *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	ret[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	ret = NULL;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end], set))
		end--;
	end++;
	if (start >= end)
		return (ft_strdup(""));
	ret = (char *) malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (ret);
	fill_ret(ret, s1, start, end);
	return (ret);
}
