/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:20:15 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/02 14:10:00 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	if (!n)
		return (0);
	while ((i < (n - 1))
		&& *(unsigned char *) &s1[i] == *(unsigned char *) &s2[i])
		i++;
	ret = *(unsigned char *) &s1[i] - *(unsigned char *) &s2[i];
	return (ret);
}
