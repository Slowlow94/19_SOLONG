/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:14:21 by salowie           #+#    #+#             */
/*   Updated: 2023/09/26 17:58:15 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	where_is_exit(t_datas *datas)
{
	int	y;
	int	x;

	y = 0;
	while (y < datas->map->h)
	{
		x = 0;
		while (x < datas->map->w)
		{
			if (datas->map->map[y][x] == 'E')
			{
				datas->exit_x = x;
				datas->exit_y = y;
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
	mappy = malloc(sizeof(char *) * (d->map->h + 1));
	if (mappy == NULL)
	{
		free_all(d);
		exit(1);
	}
	while (y < d->map->h)
	{
		mappy[y] = ft_strdup(d->map->map[y]);
		y++;
	}
	where_is_p(d);
	where_is_exit(d);
	find_exit(mappy, d);
}

int	find_exit(char **mappy, t_datas *d)
{
	static int	nbr_c;
	static int	y;
	static int	x;

	y = d->pers_y;
	x = d->exit_x;
	nbr_c = d->nbr_of_collect;
	if (mappy[y][x] == mappy[d->exit_y][d->exit_x] && nbr_c == 0)
		return (0);
	return (0);
}
