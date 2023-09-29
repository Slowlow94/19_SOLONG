/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:14:21 by salowie           #+#    #+#             */
/*   Updated: 2023/09/29 10:39:22 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_mappy(t_datas *d)
{
	char	**mappy;
	int		y;

	y = 0;
	mappy = malloc(sizeof(char *) * (d->map->h + 1));
	if (mappy == NULL)
	{
		ft_error_map(ERROR_MALLOC, d);
		free_map(mappy);
		exit(1);
	}
	while (y < d->map->h)
	{
		mappy[y] = ft_strdup(d->map->map[y]);
		y++;
	}
	mappy[y] = NULL;
	return (mappy);
}

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

void	dupmap_init(t_datas *d)
{
	char	**mappy;
	int		y;

	y = 0;
	d->collect_cpy = 0;
	mappy = create_mappy(d);
	where_is_p(d);
	find_exit(mappy, d, d->pers_y, d->pers_x);
	if (d->check_exit == 0)
	{
		free_map(mappy);
		ft_error_map(ERROR_PATH, d);
	}
}

void	find_exit(char **mappy, t_datas *d, int y, int x)
{
	if (y < 0 || x < 0 || y > d->map->h || x > d->map->w)
		return ;
	if ((mappy[y][x] == 'E' || d->is_exit == true) 
		&& d->collect_cpy == d->nbr_of_collect)
		d->check_exit = true;
	if (mappy[y][x] == '1' || mappy[y][x] == '2')
		return ;
	if (mappy[y][x] == 'E' && d->collect_cpy != d->nbr_of_collect)
	{
		d->is_exit = true;
		return ;
	}
	else if (mappy[y][x] == 'C' || mappy[y][x] == '0')
	{
		if (mappy[y][x] == 'C')
			d->collect_cpy++;
		mappy[y][x] = '2';
	}
	find_exit(mappy, d, y + 1, x);
	find_exit(mappy, d, y - 1, x);
	find_exit(mappy, d, y, x + 1);
	find_exit(mappy, d, y, x - 1);
}
