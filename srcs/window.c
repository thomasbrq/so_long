/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:27:19 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/11 09:27:32 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/errors.h"
#include "../includes/configuration.h"

static	t_image	load_character_images(t_mlx mlx, t_image *image)
{
	image->p_up = mlx_xpm_file_to_image(mlx.mlx, "images/p_up.xpm",
			&image->width, &image->heigth);
	image->p_down = mlx_xpm_file_to_image(mlx.mlx, "images/p_down.xpm",
			&image->width, &image->heigth);
	image->p_left = mlx_xpm_file_to_image(mlx.mlx, "images/p_left.xpm",
			&image->width, &image->heigth);
	image->p_right = mlx_xpm_file_to_image(mlx.mlx, "images/p_right.xpm",
			&image->width, &image->heigth);
	return (*image);
}

static t_image	load_images(t_mlx mlx, t_image *image)
{
	image->floor = mlx_xpm_file_to_image(mlx.mlx, "images/floor.xpm",
			&image->width, &image->heigth);
	image->wall = mlx_xpm_file_to_image(mlx.mlx, "images/wall.xpm",
			&image->width, &image->heigth);
	image->collectable = mlx_xpm_file_to_image(mlx.mlx,
			"images/collectable.xpm", &image->width, &image->heigth);
	image->exit = mlx_xpm_file_to_image(mlx.mlx, "images/exit.xpm",
			&image->width, &image->heigth);
	return (*image);
}

static int	destroy_all(t_strc *strc)
{
	free_map(&(*strc).map);
	mlx_clear_window(strc->mlx->mlx, strc->mlx->win);
	mlx_destroy_window(strc->mlx->mlx, strc->mlx->win);
	exit(0);
}

static int	key_trigger(int keycode, t_strc *strc)
{
	if (keycode == 53)
		destroy_all(strc);
	if (keycode == 13 || keycode == 126)
		if (p_up(strc))
			destroy_all(strc);
	if (keycode == 2 || keycode == 124)
		if (p_right(strc))
			destroy_all(strc);
	if (keycode == 1 || keycode == 125)
		if (p_down(strc))
			destroy_all(strc);
	if (keycode == 0 || keycode == 123)
		if (p_left(strc))
			destroy_all(strc);
	ft_printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	ft_printf("Step = %d | Collectable = %d", strc->player->step,
		strc->player->collectable);
	return (0);
}

void	init_mlx(t_map **map, t_player *player)
{
	t_mlx		mlx;
	t_image		images;
	t_strc		strc;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		print_error("Initialisation failed.\n");
		return ;
	}
	mlx.win = mlx_new_window(mlx.mlx, ((*map)->width * TILE_W),
			((*map)->height * TILE_H), "Les aventures de Meu!");
	strc.mlx = &mlx;
	strc.map = *map;
	strc.images = &images;
	strc.player = player;
	images = load_images(mlx, &images);
	images = load_character_images(mlx, &images);
	print_map(strc);
	print_active(strc, 'P', player->x, player->y);
	mlx_hook(mlx.win, 2, 1L << 0, key_trigger, &strc);
	mlx_hook(mlx.win, 17, 1L << 17, destroy_all, &strc);
	mlx_loop(mlx.mlx);
}
