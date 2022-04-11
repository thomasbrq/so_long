/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:53:55 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/17 16:44:10 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_and_count(char *str, int *ret)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*ret += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*ret += ft_strlen(str);
}
