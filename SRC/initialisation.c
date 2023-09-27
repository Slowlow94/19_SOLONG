/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:00:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 19:25:07 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_datas *datas, char *lib)
{
	datas->img = NULL;
	datas->is_exit = false;
	datas->yes_exit = false;
	datas->check_exit = false;
	datas->nbr_exit = 0;
	datas->nbr_of_collect = 0;
	datas->collect_cpy = 0;
	datas->nbr_of_moves = 0;
	datas->nbr_of_player = 0;
	datas->map = malloc(sizeof(t_map));
	if (datas->map == NULL)
	{
		free_all(datas);
		exit(1);
	}
	datas->map->map = convert_ber(lib, datas);
}

int	map_init(t_datas *datas)
{
	datas->mlx = mlx_init();
	if (!datas->mlx)
		ft_error(ERROR_MLX, datas);
	datas->win = mlx_new_window(datas->mlx, datas->map->w * 64, 
			datas->map->h * 64, "paradise");
	if (!datas->win)
	{
		mlx_destroy_window(datas->mlx, datas->win);
		ft_error(ERROR_WIN, datas);
	}
	init_images(datas);
	parsing_map(datas);
	mlx_hook(datas->win, 17, 0, close_event, datas);
	mlx_hook(datas->win, 2, 0, key_event, datas);
	mlx_loop(datas->mlx);
	return (0);
}

int	parsing_map(t_datas *d)
{
	int	x;
	int	y;
	int	size_tile;

	size_tile = 64;
	y = 0;
	while (y < d->map->h)
	{
		x = 0;
		while (x < d->map->w)
		{
			mlx_put_image_to_window(d->mlx, d->win, 
				d->img->ground.xpm, x * size_tile, y * size_tile);
			images_placement(d, size_tile, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	images_placement(t_datas *d, int size_tile, int y, int x)
{
	if (d->map->map[y][x] == '1')
		mlx_put_image_to_window(d->mlx, d->win, 
			d->img->wall.xpm, x * size_tile, y * size_tile);
	if (d->map->map[y][x] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, 
			d->img->collect.xpm, x * size_tile, y * size_tile);
	if (d->map->map[y][x] == 'P')
		mlx_put_image_to_window(d->mlx, d->win, 
			d->img->pony.xpm, x * size_tile, y * size_tile);
	if (d->map->map[y][x] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, 
			d->img->exit.xpm, x * size_tile, y * size_tile);
}

int	init_images(t_datas *d)
{
	d->img = malloc(sizeof(t_images));
	if (!d->img)
		ft_error(ERROR_IMG, d);
	d->img->wall.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/haystack_good.xpm", 
			&d->img->wall.w, &d->img->wall.h);
	if (!d->img->wall.xpm)
		ft_error(ERROR_IMG, d);
	d->img->ground.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/grass_good.xpm", 
			&d->img->ground.w, &d->img->ground.h);
	if (!d->img->ground.xpm)
		ft_error(ERROR_IMG, d);
	d->img->collect.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/flower_good.xpm", 
			&d->img->collect.w, &d->img->collect.h);
	if (!d->img->collect.xpm)
		ft_error(ERROR_IMG, d);
	d->img->exit.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/rainbow_Good.xpm", 
			&d->img->exit.w, &d->img->exit.h);
	if (!d->img->exit.xpm)
		ft_error(ERROR_IMG, d);
	d->img->pony.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/pinkie_Good.xpm", 
			&d->img->pony.w, &d->img->pony.h);
	if (!d->img->collect.xpm)
		ft_error(ERROR_IMG, d);
	return (0);
}
