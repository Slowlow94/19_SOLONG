/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:00:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/21 18:51:55 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int key_event(int keycode, void *param)
{
 	t_datas *datas;
	
	datas = (t_datas *)param;
    if (keycode == 53)
	{
        mlx_destroy_window(datas->mlx, datas->win);
		exit (0);
	}
	if (keycode == 123) // vers la gauche
		to_the_left(datas);
	else if (keycode == 124) // vers la droite
		to_the_right(datas);
	else if (keycode == 125) // vers le bas
		to_the_bottom(datas);
	else if (keycode == 126) // vers le haut
		to_the_top(datas);
	parsing_map(datas);
    return (0);
}

int	map_init(t_datas *datas)
{
	datas->mlx = mlx_init();
	if (!datas->mlx)
		return (ft_error('l'));
	datas->win = mlx_new_window(datas->mlx, datas->map->w * 64, datas->map->h * 64, "paradise");
	if (!datas->win)
	{
		mlx_destroy_window(datas->mlx, datas->win);
		return (ft_error('w'));
	}
	init_images(datas);
	parsing_map(datas);
	mlx_hook(datas->win, 17, 0, key_event, datas);
	mlx_hook(datas->win, 2, 0, key_event, datas);
	mlx_loop(datas->mlx);
	return (0);
}

int	parsing_map(t_datas *d)
{
	int	st;
	int	x;
	int	y;

	st = 64;
	y = 0;
	while (y < d->map->h)
	{
		x = 0;
		while (x < d->map->w)
		{
			mlx_put_image_to_window(d->mlx, d->win, d->img->ground.xpm, x * st, y * st);
			if (d->map->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->img->wall.xpm, x * st, y * st);
			if (d->map->map[y][x] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->img->collect.xpm, x * st, y * st);
			if (d->map->map[y][x] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->img->poney.xpm, x * st, y * st);
			if (d->map->map[y][x] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->img->exit.xpm, x * st, y * st);
			x++;
		}
		y++;
	}
	return (0);
}

int	init_images(t_datas *d)
{
	d->img = malloc(sizeof(t_images));
	if (!d->img)
		ft_error('i');
	d->img->wall.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/haystack_good.xpm", 
		&d->img->wall.w, &d->img->wall.h);
	if (!d->img->wall.xpm)
		ft_error('i');
	d->img->ground.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/grass_good.xpm", 
		&d->img->ground.w, &d->img->ground.h);
	if (!d->img->ground.xpm)
		ft_error('i');
	d->img->collect.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/flower_good.xpm", 
		&d->img->collect.w, &d->img->collect.h);
	if (!d->img->collect.xpm)
		ft_error('i');
	d->img->poney.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/pinkie_Good.xpm", 
		&d->img->poney.w, &d->img->poney.h);
	if (!d->img->collect.xpm)
		ft_error('i');
	d->img->exit.xpm = mlx_xpm_file_to_image(d->mlx, "XPM/rainbow_Good.xpm", 
		&d->img->exit.w, &d->img->exit.h);
	if (!d->img->exit.xpm)
		ft_error('i');
	return (0);
}

