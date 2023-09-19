/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:45:18 by salowie           #+#    #+#             */
/*   Updated: 2023/04/13 11:31:01 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				c;
	unsigned const char	*str1;
	unsigned const char	*str2;

	c = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (str1[c] == str2[c] && str1[c] && str2[c] && --n)
		c++;
	return (str1[c] - str2[c]);
}
