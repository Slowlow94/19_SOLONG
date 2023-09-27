/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 19:19:11 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *error_msg, t_datas *datas)
{
	ft_putstr(error_msg);
	free_all(datas);
	exit (1);
}

void	free_images(t_datas *d)
{
	if (d == NULL || d->img == NULL)
		return ;
	if (d->img->wall.xpm)
		mlx_destroy_image(d->mlx, d->img->wall.xpm);
	if (d->img->ground.xpm)
		mlx_destroy_image(d->mlx, d->img->ground.xpm);
	if (d->img->collect.xpm)
		mlx_destroy_image(d->mlx, d->img->collect.xpm);
	if (d->img->pony.xpm)
		mlx_destroy_image(d->mlx, d->img->pony.xpm);
	if (d->img->exit.xpm)
		mlx_destroy_image(d->mlx, d->img->exit.xpm);
	if (d->img)
		free(d->img);
	else
		return ;
}

void	free_map(char **mappy)
{
	int	y;

	y = 0;
	if (!mappy)
		return ;
	while (mappy && mappy[y])
	{
		free(mappy[y]);
		y++;
	}
	free(mappy);
}

void	free_all(t_datas *d)
{
	int	y;

	y = 0;
	if (!d)
		return ;
	if (d->img)
		free_images(d);
	if (d->map)
	{
		while (y < d->map->h)
		{
			free(d->map->map[y]);
			y++;
		}
		free(d->map->map);
		free(d->map);
	}
	free(d);
}

int	main(int argc, char **argv)
{
	t_datas	*datas;
	char	*lib;

	lib = argv[1];
	datas = malloc(sizeof(t_datas));
	if (datas == NULL)
	{
		free_all(datas);
		exit(1);
	}
	if (argc != 2)
		ft_error(ERROR_ARG, datas);
	if (check_format_ber(lib) != 0)
		ft_error(ERROR_FILE, datas);
	init_variables(datas, lib);
	check_map(datas);
	dupmap_init(datas);
	map_init(datas);
	return (0);
}
