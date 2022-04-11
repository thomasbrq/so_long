/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:02:57 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/28 12:35:10 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	ret = NULL;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *) &s[i] == (unsigned char) c)
		{
			ret = (unsigned char *) &s[i];
			return (ret);
		}
		i++;
	}
	return (ret);
}
