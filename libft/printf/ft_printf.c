/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:40:54 by tbraquem          #+#    #+#             */
/*   Updated: 2022/03/17 16:45:01 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void	ft_parser(char c, va_list param, int *ret)
{
	if (c == 'c')
	{
		ft_putchar_fd((char) va_arg(param, int), 1);
		*ret += 1;
	}
	else if (c == 's')
		ft_putstr_and_count((char *) va_arg(param, char *), ret);
	else if (c == 'p')
		ptr_to_hex((unsigned long int) va_arg(param, unsigned long int), ret);
	else if (c == 'x')
		nbr_ui_to_hex((unsigned int) va_arg(param, unsigned int), ret, 1);
	else if (c == 'X')
		nbr_ui_to_hex((unsigned int) va_arg(param, unsigned int), ret, 2);
	else if (c == 'd')
		ft_decimalb10((int) va_arg(param, int), ret);
	else if (c == 'i')
		ft_intb10((int) va_arg(param, int), ret);
	else if (c == 'u')
		ft_uint10((unsigned int) va_arg(param, unsigned int), ret);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		*ret += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		param;
	size_t		count;
	int			ret;

	count = 0;
	ret = 0;
	va_start(param, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			count++;
			ft_parser(str[count], param, &ret);
		}
		else
		{
			ft_putchar_fd(str[count], 1);
			ret++;
		}
		count++;
	}
	va_end(param);
	return (ret);
}
