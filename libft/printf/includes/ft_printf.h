/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:27:55 by tbraquem          #+#    #+#             */
/*   Updated: 2022/04/05 11:35:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../../libft.h"

int		ft_printf(const char *str, ...);
void	ft_intb10(int n, int *ret);
void	ft_decimalb10(int n, int *ret);
void	nbr_ui_to_hex(unsigned int n, int *ret, int choice);
void	ft_uint10(unsigned int n, int *ret);
void	ptr_to_hex(unsigned long int n, int *ret);
void	ft_putstr_and_count(char *str, int *ret);

#endif
