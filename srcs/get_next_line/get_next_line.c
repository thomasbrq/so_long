/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:18:14 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/03 13:49:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static int	nbr;
	static char	buff[BUFFER_SIZE / BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	if (nbr == 0)
	{
		nbr = read(fd, buff, 1);
		buff[nbr] = '\0';
	}
	if (nbr > 0 && buff[0] != '\0')
		result = ft_read(fd, buff, result, nbr);
	else
		return (NULL);
	return (result);
}

char	*ft_read(int fd, char *buff, char *result, int nbr)
{
	while (nbr > 0 && ft_sstrchr(result, '\n'))
	{
		result = ft_sstrjoin(result, buff);
		nbr = read(fd, buff, 1);
		buff[nbr] = '\0';
	}
	return (result);
}
