/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/13 14:23:05 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(void)
{
	return (NULL);
}

int	main(void)
{
	void			*mlx;
	void			*window;
	t_img_struct	img;
	
	mlx = mlx_init();
	if (!mlx)
		ft_error();
	window = mlx_new_window(mlx, 1600, 1200, "paradise");
	if (!window)
	{
		mlx_destroy_window(mlx, window);
		ft_error();
	}
	img.ptr_img = mlx_xpm_file_to_image(mlx, "XPM/blue_poney.xpm", &img.width, &img.height);
	mlx_put_image_to_window(mlx, window, img.ptr_img, 0, 0);
	mlx_loop(mlx);
}
