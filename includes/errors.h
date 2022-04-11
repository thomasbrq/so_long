/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:55:09 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/11 09:57:55 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include <unistd.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../libft/printf/includes/ft_printf.h"
# include "game.h"

void	print_error(char *str);
void	free_map(t_map **map);
void	free_active(t_active **active, int height);

#endif
