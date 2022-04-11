/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:05:18 by tbraquem          #+#    #+#             */
/*   Updated: 2022/02/28 15:23:08 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					ret;
	unsigned char		*ss1;
	unsigned char		*ss2;

	i = 0;
	ret = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	if (n == 0)
		return (ret);
	while (ss1[i] == ss2[i] && (i < (n - 1)) && ss1[i] && ss2[i])
		i++;
	ret = (ss1[i] - ss2[i]);
	return (ret);
}
