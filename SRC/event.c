/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:49:08 by salowie           #+#    #+#             */
/*   Updated: 2023/09/26 17:35:08 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int keycode, void *param)
{
	t_datas	*datas;

	datas = (t_datas *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(datas->mlx, datas->win);
		exit (0);
	}
	if (keycode == 123)
		to_the_left(datas);
	else if (keycode == 124)
		to_the_right(datas);
	else if (keycode == 125)
		to_the_bottom(datas);
	else if (keycode == 126)
		to_the_top(datas);
	parsing_map(datas);
	return (0);
}

int	close_event(t_datas *datas)
{
	free_all(datas);
	exit(0);
}
