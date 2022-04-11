/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:55:45 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/09 14:27:09 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"

void	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->map[i] != NULL)
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
}

void	free_active(t_active **active, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(active[i]);
		i++;
	}
	free(*active);
}
