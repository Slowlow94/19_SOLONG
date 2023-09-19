/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:41:15 by salowie           #+#    #+#             */
/*   Updated: 2023/05/11 17:42:33 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (!(n == -2147483648))
	{
		if (n < 0)
		{
			n *= -1;
			i += ft_putchar('-');
		}
		if (n > 9)
		{
			i += ft_putnbr(n / 10);
			i += ft_putnbr(n % 10);
		}
		else if (n >= 0 && n <= 9)
			i += ft_putchar(n + '0');
	}
	else
		i += ft_putstr("-2147483648");
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_unsigned_putnbr(n / 10);
		i += ft_unsigned_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_put_hexa(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_put_hexa(n / 16, c);
		i += ft_put_hexa(n % 16, c);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				i += ft_putchar(n -10 + 'a');
			if (c == 'X')
				i += ft_putchar(n -10 + 'A');
		}
	}
	return (i);
}
