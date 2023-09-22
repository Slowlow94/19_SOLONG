/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:35:06 by salowie           #+#    #+#             */
/*   Updated: 2023/09/22 18:36:59 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_datas *datas)
{
	count_map(datas->map);
	nbr_of_collectible(datas);
	if (same_lenght_and_exit(datas) == 1 || is_wall_all_around(datas) == 1)
	{
		if (datas->yes_exit == false)
			ft_error('e');
		else
			ft_error('m');
		free_all(datas);
		exit (1);
	}
	return (0);
}

int	same_lenght_and_exit(t_datas *d)
{
	int	x;
	int	y;
	int	lenght_of_x;

	y = 0;
	lenght_of_x = 0;
	while (d->map->map[y] != NULL)
	{
		x = 0;
		while (d->map->map[y][x] != '\0')
		{
			if (d->map->map[y][x] == 'E')
				d->yes_exit = 1;
			x++;
		}
		if (lenght_of_x == 0)
			lenght_of_x = x;
		if (x != lenght_of_x)
			return (1);
		y++;
	}
	if (d->yes_exit == 0)
		return (1);
	return (0);
}

int	is_wall_all_around(t_datas *d)
{
	int	x;
	int	y;
	int	lenght_of_x;
	int	lenght_of_y;

	y = 0;
	lenght_of_x = d->map->w;
	lenght_of_y = d->map->h;
	while (y < d->map->h)
	{
		x = 0;
		while (x < d->map->w)
		{
			if (d->map->map[0][x] != '1' || d->map->map[lenght_of_y - 1][x] != '1'
				|| d->map->map[y][0] != '1' || d->map->map[y][lenght_of_x - 1] != '1')
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void count_map(t_map *map)
{
    int		i;
    int		currentLineWidth;
    
    map->h = 0;
    map->w = 0;
	i = 0;
    while (map->map[i] != NULL)
	{
        currentLineWidth = 0;
        while (map->map[i][currentLineWidth] != '\0')
            currentLineWidth++;
        if(currentLineWidth > map->w)
            map->w = currentLineWidth;
        i++;
        map->h++;
    }
}