/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:22:52 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 19:23:47 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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