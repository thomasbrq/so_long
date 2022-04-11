/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:48:09 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/02 16:57:36 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_ret(int n, char *ret, size_t *count)
{
	size_t	i;
	int		nn;

	if (n < 0)
		nn = -n;
	else
		nn = n;
	i = 0;
	while (nn >= 10)
	{
		nn = nn / 10;
		i++;
	}
	i++;
	if (n < 0)
		*count = (i + 2);
	else
		*count = (i + 1);
	ret = malloc(*count * sizeof(char));
	return (ret);
}

static char	*fill_ret(int n, char *ret, size_t count)
{
	size_t	i;
	int		save;

	i = 1;
	save = 0;
	if (n < 0)
		save = -n;
	else
		save = n;
	ret[count - 1] = '\0';
	count--;
	while (i <= (count))
	{
		if (save >= 10)
		{
			ret[count - i] = (save % 10) + '0';
			save = save / 10;
		}
		else
			ret[count - i] = save + '0';
		i++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*ret;
	size_t			count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ret = NULL;
	count = 0;
	ret = malloc_ret(n, ret, &count);
	if (!ret)
		return (ret);
	ret = fill_ret(n, ret, count);
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
