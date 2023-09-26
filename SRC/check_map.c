/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:35:06 by salowie           #+#    #+#             */
/*   Updated: 2023/09/26 17:41:53 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_datas *datas)
{
	count_map(datas->map);
	if (same_lenght(datas) == 1 || is_wall_all_around(datas) == 1 
		|| is_exit_or_too_much(datas) == 1 || nbr_of_collectible(datas) == 1)
	{
		if (datas->nbr_exit > 1)
			ft_error('t');
		else if (datas->yes_exit == false)
			ft_error('e');
		else if (datas->nbr_of_collect < 1)
			ft_error('c');
		else
			ft_error('m');
		free_all(datas);
		exit (1);
	}
	return (0);
}

int	same_lenght(t_datas *d)
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
			x++;
		}
		if (lenght_of_x == 0)
			lenght_of_x = x;
		if (x != lenght_of_x)
			return (1);
		y++;
	}
	return (0);
}

int	is_exit_or_too_much(t_datas *d)
{
	int	x;
	int	y;

	y = 0;
	while (d->map->map[y] != NULL)
	{
		x = 0;
		while (d->map->map[y][x] != '\0')
		{
			if (d->map->map[y][x] == 'E')
			{
				d->yes_exit = 1;
				d->nbr_exit += 1;
			}
			x++;
		}
		y++;
	}
	if (d->yes_exit == 0)
		return (1);
	if (d->nbr_exit > 1)
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
			if (d->map->map[0][x] != '1' 
				|| d->map->map[lenght_of_y - 1][x] != '1'
				|| d->map->map[y][0] != '1' 
				|| d->map->map[y][lenght_of_x - 1] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	count_map(t_map *map)
{
	int	i;
	int	currentlinewidth;

	map->h = 0;
	map->w = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		currentlinewidth = 0;
		while (map->map[i][currentlinewidth] != '\0')
			currentlinewidth++;
		if (currentlinewidth > map->w)
			map->w = currentlinewidth;
		i++;
		map->h++;
	}
}
