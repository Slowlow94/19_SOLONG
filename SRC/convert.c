/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:39:59 by salowie           #+#    #+#             */
/*   Updated: 2023/09/26 17:37:00 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format_ber(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (1);
	return (ft_strcmp_mod(str + len - 4, ".ber"));
}

int	ft_strcmp_mod(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**convert_ber(char *lib)
{
	int		fd;
	char	**map;
	char	*strings_collected;

	map = NULL;
	fd = open(lib, O_RDONLY);
	if (fd < 0)
	{
		ft_error('o');
		exit (0);
	}
	strings_collected = collect_strings(fd);
	if (check_char(strings_collected) == 1)
	{
		ft_error('m');
		exit (0);
	}
	map = ft_split(strings_collected, '\n');
	return (map);
}

int	check_char(char *strings_collected)
{
	int	i;

	i = 0;
	while (strings_collected && strings_collected[i])
	{
		if (strings_collected[i] == '\n' && strings_collected[i + 1] == '\n')
			return (1);
		else if (strings_collected[i] == '\n' || strings_collected[i] == '0' 
			|| strings_collected[i] == '1' || strings_collected[i] == 'C' 
			|| strings_collected[i] == 'E' || strings_collected[i] == 'P')
			i++;
		else
			return (1);
	}
	return (0);
}

char	*collect_strings(int fd)
{
	char	*strings_collected;
	char	*str;
	char	*temp;

	str = get_next_line(fd);
	strings_collected = NULL;
	while (str)
	{
		temp = strings_collected;
		strings_collected = ft_strjoin_mod(temp, str);
		free(temp);
		free(str);
		str = get_next_line(fd);
	}
	return (strings_collected);
}
