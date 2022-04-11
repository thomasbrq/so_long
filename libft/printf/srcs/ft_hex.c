/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:08:33 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/17 14:49:56 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	int_to_hexchar(int n);

void	nbr_ui_to_hex(unsigned int n, int *ret, int choice)
{
	if (n >= 16)
	{
		nbr_ui_to_hex((n / 16), ret, choice);
		nbr_ui_to_hex((n % 16), ret, choice);
	}
	else
	{
		if (choice == 1)
			ft_putchar_fd(int_to_hexchar(n), 1);
		else if (choice == 2)
			ft_putchar_fd(ft_toupper(int_to_hexchar(n)), 1);
		*ret += 1;
	}
}

void	nbr_ptr_to_hex(unsigned long int n, int *ret)
{
	if (n >= 16)
	{
		nbr_ptr_to_hex((n / 16), ret);
		nbr_ptr_to_hex((n % 16), ret);
	}
	else
	{
		ft_putchar_fd(int_to_hexchar(n), 1);
		*ret += 1;
	}
}

void	ptr_to_hex(unsigned long int n, int *ret)
{
	ft_putstr_fd("0x", 1);
	*ret += 2;
	nbr_ptr_to_hex(n, ret);
}

char	int_to_hexchar(int n)
{
	char	*caractere;

	caractere = "0123456789abcdef";
	return (caractere[n]);
}
