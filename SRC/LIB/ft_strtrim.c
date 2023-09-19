/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:34:47 by salowie           #+#    #+#             */
/*   Updated: 2023/04/25 17:46:02 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		lenght;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	lenght = ft_strlen(s1);
	while (s1[j] && is_inset(set, s1[j]))
		j++;
	while (j < lenght && is_inset(set, s1[lenght - 1]))
		lenght--;
	res = malloc(sizeof(char) * (lenght - j + 1));
	if (!res)
		return (NULL);
	while (j < lenght)
	{
		res[i] = s1[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
