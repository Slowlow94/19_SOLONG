/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:12:52 by salowie           #+#    #+#             */
/*   Updated: 2023/09/21 18:50:58 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	where_is_p(t_datas *datas)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < datas->map->h)
	{
		x = 0;
		while (x < datas->map->w)
		{
			if (datas->map->map[y][x] == 'P')
			{
				datas->pos_of_x = x;
				datas->pos_of_y = y;
			}
			x++;
		}
		y++;
	}
}

void	to_the_left(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pos_of_y][datas->pos_of_x - 1] == '0' 
		|| datas->map->map[datas->pos_of_y][datas->pos_of_x - 1] == 'C')
		{
			datas->map->map[datas->pos_of_y][datas->pos_of_x] = '0';
			datas->map->map[datas->pos_of_y][datas->pos_of_x - 1] = 'P';
		}
}

void	to_the_right(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pos_of_y][datas->pos_of_x + 1] == '0' 
		|| datas->map->map[datas->pos_of_y][datas->pos_of_x + 1] == 'C')
		{
			datas->map->map[datas->pos_of_y][datas->pos_of_x] = '0';
			datas->map->map[datas->pos_of_y][datas->pos_of_x + 1] = 'P';
		}
}

void	to_the_bottom(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pos_of_y + 1][datas->pos_of_x] == '0' 
		|| datas->map->map[datas->pos_of_y + 1][datas->pos_of_x] == 'C')
		{
			datas->map->map[datas->pos_of_y][datas->pos_of_x] = '0';
			datas->map->map[datas->pos_of_y + 1][datas->pos_of_x] = 'P';
		}
}

void	to_the_top(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pos_of_y - 1][datas->pos_of_x] == '0' 
		|| datas->map->map[datas->pos_of_y - 1][datas->pos_of_x] == 'C')
		{
			datas->map->map[datas->pos_of_y][datas->pos_of_x] = '0';
			datas->map->map[datas->pos_of_y - 1][datas->pos_of_x] = 'P';
		}
}
