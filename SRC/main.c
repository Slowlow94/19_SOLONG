/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/14 19:01:15 by Sarah            ###   ########.fr       */
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
		i--;
	}
	free(map);
}

char	**fill_map(t_list *strings_collected)
{
	char **map;
	int size_y;
	int	i;

	size_y = ft_lstsize(strings_collected);
	map = (char **)malloc((size_y + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < size_y)
	{
		map[i] = ft_strdup((char *)strings_collected->content);
		// ft_printf("strings_collected : %s", map[i]);
		if (!map[i])
			free_map(i, map);
		i++;
		strings_collected = strings_collected->next;
	}
	map[size_y] = NULL;
	return (map);	
}

t_list	*collect_strings(int fd)
{
	t_list *strings_collected;
	t_list *new_node;
	char *str;

	str = get_next_line(fd);
	strings_collected = NULL;
	while (str)
	{
		new_node = ft_lstnew(str);
		if (strings_collected == NULL)
			strings_collected = new_node;
		else
			ft_lstadd_back(&strings_collected, new_node);
		free(str);
		str = get_next_line(fd);
	}
	return (strings_collected);
}

char	**convert_ber()
{
	int		fd;
	char	*lib;
	char	**map;
	t_list	*strings_collected;

	lib = "map.ber";
	fd = open(lib, O_RDONLY);
	strings_collected = collect_strings(fd);
	map = fill_map(strings_collected);
	return (map);
}

int	main(void)
{
	// void			*mlx;
	// void			*window;
	// t_img_struct	img;
	char			**map;
	int				i;
	int				x;

	x = 0;
	i = 0;
	map = convert_ber();
	while (map[i])
	{
		while(map[i][x++])
			ft_printf("%c", map[i][x]);
		i++;
		x = 0;
	}
	// mlx = mlx_init();
	// if (!mlx)
	// 	ft_error();
	// window = mlx_new_window(mlx, 1600, 1200, "paradise");
	// if (!window)
	// {
	// 	mlx_destroy_window(mlx, window);
	// 	ft_error();
	// }
	// img.ptr_img = mlx_xpm_file_to_image(mlx, "XPM/blue_poney.xpm", &img.width, &img.height);
	// mlx_put_image_to_window(mlx, window, img.ptr_img, 0, 0);
	// mlx_loop(mlx);
	return (0);
}
