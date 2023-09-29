/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:22:52 by salowie           #+#    #+#             */
/*   Updated: 2023/09/29 10:38:18 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	nbr_of_collectible(t_datas *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->map->h)
	{
		x = 0;
		while (x < d->map->w)
		{
			if (d->map->map[y][x] == 'C')
				d->nbr_of_collect += 1;
			x++;
		}
		y++;
	}
	if (d->nbr_of_collect < 1)
		return (1);
	return (0);
}

int	nbr_of_player(t_datas *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->map->h)
	{
		x = 0;
		while (x < d->map->w)
		{
			if (d->map->map[y][x] == 'P')
				d->nbr_of_player += 1;
			x++;
		}
		y++;
	}
	if (d->nbr_of_player > 1)
		return (1);
	return (0);
}
