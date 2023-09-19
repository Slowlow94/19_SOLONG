/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:06:24 by salowie           #+#    #+#             */
/*   Updated: 2023/04/04 17:06:26 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (--n)
	{
		if (*ptr1 == *ptr2)
		{
			ptr1++;
			ptr2++;
		}
		else
			return (*ptr1 - *ptr2);
	}
	return (*ptr1 - *ptr2);
}
