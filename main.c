/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:26:48 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/10 14:50:58 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"
#include "includes/errors.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	player;

	if (argc < 2)
	{
		print_error("Please enter a map file.\n");
		exit(1);
	}
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (-1);
	map = load_map(map, argv[1]);
	player = get_player(map);
	map = remove_player(map);
	map = get_collectable(map);
	player.direction = 2;
	player.step = 0;
	player.collectable = 0;
	init_mlx(&map, &player);
	return (0);
}
