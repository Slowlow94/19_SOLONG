/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:19:56 by salowie           #+#    #+#             */
/*   Updated: 2023/04/26 10:23:18 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bbis;

	if (!b)
		return (NULL);
	bbis = b;
	while (len--)
	{
		*bbis = (unsigned char)c;
		bbis++;
	}
	return (b);
}
