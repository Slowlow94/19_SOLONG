/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:12:52 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 16:00:52 by salowie          ###   ########.fr       */
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
				datas->pers_x = x;
				datas->pers_y = y;
			}
			x++;
		}
		y++;
	}
}

void	to_the_left(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pers_y][datas->pers_x - 1] == '0' 
		|| datas->map->map[datas->pers_y][datas->pers_x - 1] == 'C')
	{
		if (datas->map->map[datas->pers_y][datas->pers_x - 1] == 'C')
			datas->nbr_of_collect -= 1;
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y][datas->pers_x - 1] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
	}
	if (datas->map->map[datas->pers_y][datas->pers_x - 1] == 'E' 
		&& datas->nbr_of_collect == 0)
	{
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y][datas->pers_x - 1] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
		ft_printf("Congrats, you saved pinkiie !\n");
		mlx_destroy_window(datas->mlx, datas->win);
		free_all(datas);
		exit(0);
	}
}

void	to_the_right(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pers_y][datas->pers_x + 1] == '0' 
		|| datas->map->map[datas->pers_y][datas->pers_x + 1] == 'C')
	{
		if (datas->map->map[datas->pers_y][datas->pers_x + 1] == 'C')
			datas->nbr_of_collect -= 1;
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y][datas->pers_x + 1] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
	}
	if (datas->map->map[datas->pers_y][datas->pers_x + 1] == 'E'
		&& datas->nbr_of_collect == 0)
	{
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y][datas->pers_x + 1] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
		ft_printf("Congrats, you saved pinkiie !\n");
		mlx_destroy_window(datas->mlx, datas->win);
		free_all(datas);
		exit(0);
	}
}

void	to_the_bottom(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pers_y + 1][datas->pers_x] == '0' 
		|| datas->map->map[datas->pers_y + 1][datas->pers_x] == 'C')
	{
		if (datas->map->map[datas->pers_y + 1][datas->pers_x] == 'C')
			datas->nbr_of_collect -= 1;
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y + 1][datas->pers_x] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
	}
	if (datas->map->map[datas->pers_y + 1][datas->pers_x] == 'E'
		&& datas->nbr_of_collect == 0)
	{
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y + 1][datas->pers_x] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
		ft_printf("Congrats, you saved pinkiie !\n");
		mlx_destroy_window(datas->mlx, datas->win);
		free_all(datas);
		exit(0);
	}
}

void	to_the_top(t_datas *datas)
{
	where_is_p(datas);
	if (datas->map->map[datas->pers_y - 1][datas->pers_x] == '0' 
		|| datas->map->map[datas->pers_y - 1][datas->pers_x] == 'C')
	{
		if (datas->map->map[datas->pers_y -1][datas->pers_x] == 'C')
			datas->nbr_of_collect -= 1;
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y - 1][datas->pers_x] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
	}
	if (datas->map->map[datas->pers_y - 1][datas->pers_x] == 'E'
		&& datas->nbr_of_collect == 0)
	{
		datas->map->map[datas->pers_y][datas->pers_x] = '0';
		datas->map->map[datas->pers_y - 1][datas->pers_x] = 'P';
		ft_printf("Nbr_of_moves : %d\n", datas->nbr_of_moves += 1);
		ft_printf("Congrats, you saved pinkiie !\n");
		mlx_destroy_window(datas->mlx, datas->win);
		free_all(datas);
		exit(0);
	}
}
