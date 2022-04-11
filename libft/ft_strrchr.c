/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:56:19 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/28 14:43:26 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
			ret = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		ret = (char *) &s[i];
	return (ret);
}
