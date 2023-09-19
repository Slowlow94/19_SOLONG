/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:21:22 by salowie           #+#    #+#             */
/*   Updated: 2023/04/04 13:21:25 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (dstsize == 0 || dstsize <= ldst)
		return (lsrc + dstsize);
	while (src[i] && i < dstsize - ldst - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	if (dstsize != 0 && ldst + i < dstsize)
		dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
