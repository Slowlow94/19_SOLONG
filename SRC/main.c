/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 16:40:29 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char c)
{
	if (c == 'f')
		ft_printf("Smalleh, ERROR !\nCause : wrong format of text file\n");
	else if (c == 'i')
		ft_printf("Smalleh, ERROR !\nCause : image can't download\n");
	else if (c == 'l')
		ft_printf("Smalleh, ERROR !\nCause : the MinilibX is fucked up\n");
	else if (c == 'w')
		ft_printf("Smalleh, ERROR !\nCause : the window is fucked up\n");
	else if (c == 'm')
		ft_printf("Smalleh, ERROR !\nCause : invalide map bitch\n");
	else if (c == 'a')
		ft_printf("Smalleh, ERROR !\nCause : Wrong number of arguments\n");
	else if (c == 'o')
		ft_printf("Smalleh, ERROR !\nCause : opening of fd failed\n");
	else if (c == 'e')
		ft_printf("Smalleh, ERROR !\nCause : no exit\n");
	else if (c == 't')
		ft_printf("Smalleh, ERROR !\nCause : too much exit\n");
	else if (c == 'c')
		ft_printf("Smalleh, ERROR !\nCause : no collectible to collect\n");
	else if (c == 'n')
		ft_printf("Smalleh, ERROR !\nCause : no path to the exit\n");
	else
		return (0);
	return (1);
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

	datas = malloc(sizeof(t_datas));
	if (datas == NULL)
		exit(1);
	datas->map = malloc(sizeof(t_map));
	if (datas->map == NULL)
	{
		free_all(datas);
		exit(1);
	}
	init_variables(datas);
	if (argc != 2)
		return (ft_error('f'));
	if (check_format_ber(argv[1]) != 0)
		return (ft_error('f'));
	lib = argv[1];
	datas->map->map = convert_ber(lib);
	check_map(datas);
	dupmap_init(datas);
	map_init(datas);
	return (0);
}
