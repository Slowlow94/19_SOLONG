/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/14 13:55:26 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(void)
{
	return (NULL);
}

char	**fill_map(char *str, char **map)
{
}

t_list	*collect_strings(int fd)
{
	t_list *strings_collected;
	char *str;

	str = get_next_line(fd);
	while (str)
	{
		
	}
}

char	**convert_ber()
{
	int		fd;
	char	*lib;
	t_list	*strings_collected;

	lib = "map.ber";
	fd = open(lib, O_RDONLY);
	strings_collected = collect_strings(fd);
	return (map);
}

int	main(void)
{
	void			*mlx;
	void			*window;
	t_img_struct	img;
	int				fd;
	char			*lib;
	char			**map;

	lib = "map.ber";
	fd = open(lib, O_RDONLY);
	map = convert_ber();
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
