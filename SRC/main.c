/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/20 18:11:21 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(void)
{
	return (NULL);
}

void	free_map(int i, char **map)
{
	while (i >= 0)
	{
		free(map[i]);
		--i;
	}
	free(map);
}

int	images_init(void *mlx, void *window, char **map, t_map *map_size)
{
	int	size_tile;
	int	x;
	int	y;
	t_struct wall;

	ft_printf("Width : %d\n", map_size->width);
	ft_printf("h : %d\n", map_size->height);
	size_tile = 64;
	x = 0;
	y = 0;
	wall.ptr = mlx_xpm_file_to_image(mlx, "XPM/pink.xpm", &wall.width, &wall.height);
	printf("%p\n", wall.ptr);
	// if (!wall.ptr)
	// 	return (1);
	while (y < map_size->height)
	{
		x = 0;
		while (x < map_size->width)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, window, wall.ptr, x * size_tile, y * size_tile);
			x++;
		}
		y++;
	}
	return (0);
}

void	map_init(char **map, t_map *map_size)
{
	void		*mlx;
	void		*window;
	// void		*img;

	mlx = mlx_init();
	if (!mlx)
		ft_error();
	window = mlx_new_window(mlx, 1600, 1280, "paradise");
	if (!window)
	{
		mlx_destroy_window(mlx, window);
		ft_error();
	}
	// img = mlx_xpm_file_to_image(mlx, "XPM/pinkie_BIG.xpm", 0, 0);
	// mlx_put_image_to_window(mlx, window, img, 0, 0);
	images_init(mlx, window, map, map_size);
	ft_printf("test\n");
	mlx_loop(mlx);
}

t_map count_map(char **map)
{
    int		i;
    int		currentLineWidth;
	t_map	map_size;
    
	ft_printf("test");
    (&map_size)->height = 0;
    (&map_size)->width = 0;
	i = 0;
    while (map[i] != NULL)
	{
        currentLineWidth = 0;
		printf("%s\n", map[i]);
        while (map[i][currentLineWidth] != '\0')
            currentLineWidth++;
        if(currentLineWidth > map_size.width)
            map_size.width = currentLineWidth;
        i++;
        map_size.height++;
    }
	ft_printf("%d\n", map_size.height);
	ft_printf("%d\n", map_size.width);
	return (map_size);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	map_size;
	char	*lib;

	if (argc != 2)
		return (1); // error for wrong number of arguments PERROR
	if (check_format_ber(argv[1]) != 0)
		return (1); // error for wrong format of file PERROR
	lib = argv[1];
	map = convert_ber(lib);
	ft_printf("%s\n", map[0]);
	map_size = count_map(map);
	map_init(map, &map_size);
	return (0);
}
