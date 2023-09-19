/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:41:03 by salowie           #+#    #+#             */
/*   Updated: 2023/06/19 13:48:18 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_print_ptr(ptr / 16);
		i += ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			i += ft_putchar(ptr + '0');
		else
			i += ft_putchar(ptr -10 + 'a');
	}
	return (i);
}

int	ft_put_ptr(uintptr_t ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (!ptr)
		i += ft_putchar('0');
	else
		i += ft_print_ptr(ptr);
	return (i);
}

int	check_type(char c, va_list arg)
{
	if (!arg || !c)
		return (0);
	if (c == '%')
		return (ft_putchar(c));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(arg, uintptr_t)));
	if (c == 'x' || c == 'X')
		return (ft_put_hexa(va_arg(arg, uintptr_t), c));
	if (c == 'p')
		return (ft_put_ptr(va_arg(arg, uintptr_t)));
	return (0);
}

int	is_type(char c)
{
	if (!c)
		return (0);
	if (c == '%')
		return (1);
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *type, ...)
{
	va_list	arg;
	int		i;
	int		size_printf;

	va_start(arg, type);
	i = 0;
	size_printf = 0;
	if (!type)
		return (0);
	while (type[i])
	{
		if (type[i] == '%' && is_type(type[i + 1]) == 1)
		{
			size_printf += check_type(type[i + 1], arg);
			i++;
		}
		else
			size_printf += ft_putchar(type[i]);
		i++;
	}
	va_end(arg);
	return (size_printf);
}
