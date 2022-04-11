/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:48:16 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/17 16:46:24 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_intb10(int n, int *ret)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	*ret += ft_strlen(str);
	free(str);
}

void	ft_decimalb10(int n, int *ret)
{
	char	*str;

	ft_putnbr_fd(n, 1);
	str = ft_itoa(n);
	*ret += ft_strlen(str);
	free(str);
}

void	ft_uint10(unsigned int n, int *ret)
{
	if (n >= 10)
	{
		ft_uint10(n / 10, ret);
		ft_uint10(n % 10, ret);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		*ret += 1;
	}
}
