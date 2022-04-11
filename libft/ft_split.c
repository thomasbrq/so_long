/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:01:41 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/03 17:21:45 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char delimiter)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s[i])
		return (0);
	if ((s[i] != delimiter))
		count++;
	while (s[i])
	{
		if ((s[i] == delimiter) && (s[i + 1] != delimiter))
			count++;
		if ((!s[i + 1]) && (s[i] != delimiter))
			count++;
		i++;
	}
	return (count - 1);
}

static char	*array_alloc(char *array, size_t nl)
{
	array = (char *) malloc((nl) * sizeof(char));
	if (!array)
		return (NULL);
	return (array);
}

static char	*array_fill(char *array, size_t nl, char const *o, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < (nl))
	{
		array[i] = o[idx];
		i++;
		idx++;
	}
	array[i] = '\0';
	return (array);
}

static void	count_letters(char const *s, char **ret, size_t wordc, char c)
{
	size_t	letters;
	size_t	nbr;
	size_t	i;

	letters = 0;
	nbr = 0;
	i = 0;
	while (nbr < wordc)
	{
		letters = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			letters++;
			i++;
		}
		ret[nbr] = array_alloc(ret[nbr], (letters + 1));
		ret[nbr] = array_fill(ret[nbr], (letters), s, (i - letters));
		nbr++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	wordc;
	size_t	nbr;
	size_t	i;

	if (!s)
		return (NULL);
	wordc = count_word(s, c);
	nbr = 0;
	i = 0;
	ret = (char **) malloc((wordc + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[wordc] = NULL;
	count_letters(s, ret, wordc, c);
	return (ret);
}
