/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:16 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/11 09:44:41 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/errors.h"

int	count_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

int	is_in_set(char c, char *set)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (set[i])
	{
		if (set[i] == c)
			ret = 1;
		i++;
	}
	return (ret);
}

int	check_items(t_map *map)
{
	char	*flags_i;
	int		items;
	int		i;
	int		j;

	flags_i = "CEP";
	items = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_in_set(map->map[i][j], flags_i))
				items++;
			j++;
		}
		i++;
	}
	if (items < 3)
		return (-1);
	return (0);
}

int	check_duplicate(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1)
	{
		print_error("Too many player flags\n");
		return (-1);
	}
	return (0);
}
