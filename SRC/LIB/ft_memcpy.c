/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:53:44 by salowie           #+#    #+#             */
/*   Updated: 2023/04/12 18:06:56 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*desty;
	const char	*sourcy;

	desty = dst;
	sourcy = src;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*desty = *sourcy;
		desty++;
		sourcy++;
	}
	return (dst);
}
