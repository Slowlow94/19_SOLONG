/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:13:20 by salowie           #+#    #+#             */
/*   Updated: 2023/09/26 15:25:26 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*str1;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str1 = (char *)s1;
	str = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!str)
		return (0);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
