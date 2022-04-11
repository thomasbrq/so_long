/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:07:03 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/02 13:50:19 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	count;
	char			*ret;

	i = 0;
	ret = NULL;
	if (!s)
		return (NULL);
	count = ft_strlen(s);
	ret = (char *) malloc((count + 1) * sizeof(char));
	if (!ret)
		return (ret);
	while (i < count)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
