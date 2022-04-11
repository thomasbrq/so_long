/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:43:39 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/01 10:37:46 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dst;
	if (!dst && !src)
		return (dst);
	if (s < d)
		while (len-- > 0)
			d[len] = s[len];
	else
		ft_memcpy(dst, (void *) src, len);
	dst = (void *) d;
	return (dst);
}
