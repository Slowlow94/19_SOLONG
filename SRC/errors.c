/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:28:18 by salowie           #+#    #+#             */
/*   Updated: 2023/09/29 11:45:55 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *error_msg, t_datas *datas)
{
	ft_putstr(error_msg);
	free_all(datas);
	exit (1);
}

void	ft_error_map(char *error_msg, t_datas *datas)
{
	ft_putstr(error_msg);
	free(datas->map);
	free(datas);
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
	if (d->img != NULL)
		free_images(d);
	if (d->map != NULL)
		free(d->map);
	if (d->map != NULL)
		free(d->map);
	free(d);
}
