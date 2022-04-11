/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:22:27 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/11 09:45:04 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_image {
	void	*character;
	void	*p_up;
	void	*p_down;
	void	*p_left;
	void	*p_right;
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*exit;
	int		width;
	int		heigth;
}				t_image;

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		collectable;
}				t_map;

typedef struct s_active {
	void	*img;
	char	name;
	int		px;
	int		py;
	int		width;
	int		heigth;
}				t_active;

typedef struct s_player {
	void	*img;
	int		x;
	int		y;
	int		collectable;
	int		direction;
	int		step;
}				t_player;

typedef struct s_strc {
	t_mlx		*mlx;
	t_image		*images;
	t_map		*map;
	t_player	*player;
}				t_strc;

// Map
t_map		*load_map(t_map	*map, char *path);
int			check_map(t_map *map);
int			count_array(char **array);
int			is_in_set(char c, char *set);
int			check_items(t_map *map);
int			check_duplicate(t_map *map);
t_active	*load_active(t_map *map, t_active *active, t_image *images);
t_map		*remove_player(t_map *map);
t_map		*get_collectable(t_map *map);

// Player
t_player	get_player(t_map *map);
int			p_up(t_strc *strc);
int			p_down(t_strc *strc);
int			p_left(t_strc *strc);
int			p_right(t_strc *strc);

// Window
void		init_mlx(t_map **map, t_player *player);
void		print_active(t_strc strc, char c, int x, int y);

// Draw
void		print_map(t_strc strc);
void		print_active(t_strc strc, char c, int x, int y);

#endif
