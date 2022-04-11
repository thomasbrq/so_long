/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:19:11 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/23 17:19:29 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*occ;
	const char	*a;
	const char	*b;

	i = 0;
	j = 0;
	a = haystack;
	b = needle;
	if (!needle[j])
		return ((char *) a);
	while (a[i] && b[j])
	{
		j = 0;
		occ = (char *) a + i;
		while (b[j] == a[i + j] && b[j] && a[i + j] && ((i + j) < len))
			j++;
		i++;
	}
	if (!b[j])
		return (occ);
	return (NULL);
}
