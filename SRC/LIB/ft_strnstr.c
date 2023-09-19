/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:51:27 by salowie           #+#    #+#             */
/*   Updated: 2023/04/17 19:04:57 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (needle[i[1]] == '\0' || !needle)
		return ((char *)haystack);
	while (haystack[i[0]] && i[0] < len)
	{
		if (haystack[i[0]] == needle[i[1]])
		{
			i[0]++;
			i[1]++;
			if (needle[i[1]] == '\0')
				return ((char *)&haystack[i[0] - i[1]]);
		}
		if (!(haystack[i[0]] == needle[i[1]]))
		{
				i[1] = 0;
				i[2]++;
				i[0] = i[2];
		}
	}
	return (NULL);
}
