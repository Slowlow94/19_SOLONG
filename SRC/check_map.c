/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:35:06 by salowie           #+#    #+#             */
/*   Updated: 2023/09/29 10:38:00 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map(t_map *map)
{
	int	i;
	int	currentlinewidth;

	map->h = 0;
	map->w = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		currentlinewidth = 0;
		while (map->map[i][currentlinewidth] != '\0')
			currentlinewidth++;
		if (currentlinewidth > map->w)
			map->w = currentlinewidth;
		i++;
		map->h++;
	}
}

int	check_map(t_datas *datas)
{
	count_map(datas->map);
	if (same_lenght(datas) == 1 || is_wall_all_around(datas) == 1 
		|| is_exit_or_too_much(datas) == 1 || nbr_of_collectible(datas) == 1 
		|| nbr_of_player(datas) == 1)
	{
		if (datas->nbr_exit > 1)
			ft_error_map(ERROR_TOO_EXIT, datas);
		else if (datas->yes_exit == false)
			ft_error_map(ERROR_NO_EXIT, datas);
		else if (datas->nbr_of_collect < 1)
			ft_error_map(ERROR_COLLECT, datas);
		else if (datas->nbr_of_player > 1)
			ft_error_map(ERROR_P, datas);
		else
			ft_error_map(ERROR_MAP, datas);
	}
	return (0);
}
