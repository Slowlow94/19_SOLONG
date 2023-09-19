/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:44:46 by salowie           #+#    #+#             */
/*   Updated: 2023/04/04 10:44:48 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char *)dst;
	psrc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (pdst < psrc)
	{
		while (len--)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	return (dst);
}
