/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:16 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/10 13:17:35 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include "../../includes/game.h"
#include "../../includes/errors.h"

t_map	*get_collectable(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectable = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->collectable += 1;
			j++;
		}
		i++;
	}
	return (map);
}

static char	*file_to_string(char *line, char *smap)
{
	char	*ret;

	ret = NULL;
	if (!smap)
	{
		ret = ft_strdup(line);
		return (ret);
	}
	ret = ft_strjoin(smap, line);
	free(smap);
	smap = ret;
	return (smap);
}

static char	**read_and_store_map(int fd, char ***map)
{
	int		read;
	char	*line;
	char	*smap;

	line = NULL;
	read = 1;
	smap = NULL;
	while (read)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		smap = file_to_string(line, smap);
		free(line);
	}
	*map = ft_split(smap, '\n');
	free(smap);
	return (*map);
}

t_map	*load_map(t_map	*map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_error("Can't open the map file.\n");
		exit(-1);
	}
	map->map = read_and_store_map(fd, &map->map);
	if (check_map(map) == -1)
	{
		free_map(&map);
		exit(-1);
	}
	if (close(fd) == -1)
	{
		free_map(&map);
		print_error("Can't close the map file.\n");
		exit(-1);
	}
	return (map);
}

t_map	*remove_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->map[i][j] = '0';
				return (map);
			}
			j++;
		}
		i++;
	}
	return (map);
}
