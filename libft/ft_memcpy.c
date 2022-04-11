/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:17:42 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/28 14:15:20 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ret;
	const unsigned char	*p;

	i = 0;
	ret = dst;
	p = src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		ret[i] = p[i];
		i++;
	}
	return (dst);
}
