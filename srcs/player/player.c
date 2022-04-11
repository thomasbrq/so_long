/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:40:50 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/10 14:57:35 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	p_up(t_strc *strc)
{
	if (strc->map->map[strc->player->y - 1][strc->player->x] == '0')
	{
		strc->player->direction = 0;
		strc->player->step += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->player->y -= 1;
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y - 1][strc->player->x] == 'C')
	{
		strc->player->direction = 0;
		strc->player->step += 1;
		strc->player->collectable += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->map->map[strc->player->y - 1][strc->player->x] = '0';
		strc->player->y -= 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y - 1][strc->player->x] == 'E'
				&& strc->player->collectable == strc->map->collectable)
		return (1);
	return (0);
}

int	p_down(t_strc *strc)
{
	if (strc->map->map[strc->player->y + 1][strc->player->x] == '0')
	{
		strc->player->step += 1;
		strc->player->direction = 2;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->player->y += 1;
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y + 1][strc->player->x] == 'C')
	{
		strc->player->step += 1;
		strc->player->direction = 2;
		strc->player->collectable += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->map->map[strc->player->y + 1][strc->player->x] = '0';
		strc->player->y += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y + 1][strc->player->x] == 'E'
				&& strc->player->collectable == strc->map->collectable)
		return (1);
	return (0);
}

int	p_left(t_strc *strc)
{
	if (strc->map->map[strc->player->y][strc->player->x - 1] == '0')
	{
		strc->player->direction = 3;
		strc->player->step += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->player->x -= 1;
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y][strc->player->x - 1] == 'C')
	{
		strc->player->direction = 3;
		strc->player->step += 1;
		strc->player->collectable += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->map->map[strc->player->y][strc->player->x - 1] = '0';
		strc->player->x -= 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y][strc->player->x - 1] == 'E'
				&& strc->player->collectable == strc->map->collectable)
		return (1);
	return (0);
}

int	p_right(t_strc *strc)
{
	if (strc->map->map[strc->player->y][strc->player->x + 1] == '0')
	{
		strc->player->step += 1;
		strc->player->direction = 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->player->x += 1;
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y][strc->player->x + 1] == 'C')
	{
		strc->player->step += 1;
		strc->player->direction = 1;
		strc->player->collectable += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		strc->map->map[strc->player->y][strc->player->x + 1] = '0';
		strc->player->x += 1;
		print_active(*strc, '0', strc->player->x, strc->player->y);
		print_active(*strc, 'P', strc->player->x, strc->player->y);
	}
	else if (strc->map->map[strc->player->y][strc->player->x + 1] == 'E'
				&& strc->player->collectable == strc->map->collectable)
		return (1);
	return (0);
}

t_player	get_player(t_map *map)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	player.img = NULL;
	player.x = 0;
	player.y = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}
