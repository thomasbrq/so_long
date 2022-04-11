/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:13:30 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/28 14:42:55 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	o;
	char			*ret;
	size_t			i;

	o = c;
	ret = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == o)
		{
			ret = (char *) &s[i];
			return (ret);
		}
		i++;
	}
	if (s[i] == c)
		ret = (char *) &s[i];
	return (ret);
}
