/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:13:11 by salowie           #+#    #+#             */
/*   Updated: 2023/09/19 18:56:38 by salowie          ###   ########.fr       */
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


char	*collect_strings(int fd)
{
	char	*strings_collected;
	char	*str;
	char	*temp;

	str = get_next_line(fd);
	strings_collected = NULL;
	while (str)
	{
		temp = strings_collected;
		strings_collected = ft_strjoin_mod(temp, str);
		free(temp);
		free(str);
		str = get_next_line(fd);
	}
	return (strings_collected);
}

int		check_map(char *strings_collected)
{
	int	i;

	i = 0;
	while (strings_collected && strings_collected[i])
	{
		if (strings_collected[i] == '\n' && strings_collected[i + 1] == '\n')
			return (1);
		else if (strings_collected[i] == '\n' || strings_collected[i] == '0' 
			|| strings_collected[i] == '1' || strings_collected[i] == 'C' 
			|| strings_collected[i] == 'E' || strings_collected[i] == 'P')
			i++;
		else
			return (1);
	}
	return (0);
}


char	**convert_ber(char *lib)
{
	int		fd;
	char	**map;
	char	*strings_collected;

	map = NULL;
	fd = open(lib, O_RDONLY);
	if (fd < 0)
		ft_printf("open failed\n"); // ATTENTION
	strings_collected = collect_strings(fd);
	if (check_map(strings_collected) == 1)
	{
		write (1, "Error\nWrong map bitch\n", 22);
		return (ft_error());
	}
	map = ft_split(strings_collected, '\n');
	return (map);
}

int	ft_strcmp_mod(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_format_ber(char *str)
{
    size_t len = ft_strlen(str);

    if (len < 4)
        return (1);
    return (ft_strcmp_mod(str + len - 4, ".ber"));
}

int	main(int argc, char **argv)
{
	// void			*mlx;
	// void			*window;
	// t_img_struct	img;
	char			**map;
	char			*lib;
	int				i;

	i = 0;
	if (argc != 2)
		return (1); // error for wrong number of arguments PERROR
	if (check_format_ber(argv[1]) != 0)
		return (1); // error for wrong format of file PERROR
	lib = argv[1];
	map = convert_ber(lib);
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
