/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:44:05 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/10 14:52:18 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/configuration.h"

void	print_map(t_strc strc)
{
	int	i;
	int	j;

	i = 0;
	while (i < strc.map->height)
	{
		j = 0;
		while (j < strc.map->width)
		{
			print_active(strc, strc.map->map[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	print_active(t_strc strc, char c, int x, int y)
{
	void	*img;

	img = NULL;
	if (c == '0')
		img = strc.images->floor;
	else if (c == '1')
		img = strc.images->wall;
	else if (c == 'C')
		img = strc.images->collectable;
	else if (c == 'E')
		img = strc.images->exit;
	else if (c == 'P' && strc.player->direction == 0)
		img = strc.images->p_up;
	else if (c == 'P' && strc.player->direction == 1)
		img = strc.images->p_right;
	else if (c == 'P' && strc.player->direction == 2)
		img = strc.images->p_down;
	else if (c == 'P' && strc.player->direction == 3)
		img = strc.images->p_left;
	mlx_put_image_to_window(strc.mlx->mlx, strc.mlx->win, img,
		x * TILE_W, y * TILE_H);
}
