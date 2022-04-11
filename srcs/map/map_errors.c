/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:16 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/11 09:45:16 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/errors.h"

static int	check_length(char **map)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (length != ft_strlen(map[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	check_parse(t_map *map)
{
	char	*flags;
	int		i;
	int		j;

	i = 0;
	flags = "01CEP";
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j])
		{
			if (!is_in_set(map->map[i][j], flags))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_walls(char **map)
{
	int	last;
	int	i;
	int	j;

	last = count_array(map);
	i = 0;
	while (i < last)
	{
		j = 0;
		while ((i == 0 || i == (last - 1)) && map[i][j])
		{
			if (map[i][j] != '1')
				return (-1);
			j++;
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_rect(t_map **map)
{
	int	width;
	int	height;

	width = ft_strlen((*map)->map[0]);
	height = count_array((*map)->map);
	if (width == height)
	{
		print_error("The map must be rectangular\n");
		return (-1);
	}
	(*map)->width = width;
	(*map)->height = height;
	if (width < 5 || height < 3)
	{
		print_error("The map is too small\n");
		return (-1);
	}
	return (0);
}

int	check_map(t_map *map)
{
	if (check_length(map->map) == -1)
	{
		print_error("All walls must have the same length\n");
		return (-1);
	}
	if (check_parse(map) == -1)
	{
		print_error("The map must be rectangular\n");
		return (-1);
	}
	if (check_items(map) == -1)
	{
		print_error("Not enough items in the map\n");
		return (-1);
	}
	if (check_walls(map->map) == -1)
	{
		print_error("The map must be closed\n");
		return (-1);
	}
	if (check_rect(&map) == -1)
		return (-1);
	if (check_duplicate(map) == -1)
		return (-1);
	return (0);
}
