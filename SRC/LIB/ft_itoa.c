/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:50:01 by salowie           #+#    #+#             */
/*   Updated: 2023/04/18 11:48:20 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght_of_int(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	if (n >= 0 && n <= 9)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = lenght_of_int(n);
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	if (n < 0)
	{
		n = n * (-1);
		nb[0] = '-';
	}
	if (n == 0)
		nb[0] = '0';
	nb[len] = '\0';
	while (n > 0)
	{
		nb[len - 1] = (n % 10) + '0';
		n /= 10;
		len --;
	}
	return (nb);
}
