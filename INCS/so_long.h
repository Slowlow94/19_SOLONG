/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/22 18:45:31 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
#include <stdio.h> // ATTENTION

typedef struct s_im_struct {
	void	*xpm;
	int		w;
	int		h;

}				t_im_struct;

typedef struct s_images {
	t_im_struct	poney;
	t_im_struct	wall;
	t_im_struct	collect;
	t_im_struct	ground;
	t_im_struct	exit;
	// t_im_struct	final;

}				t_images;

typedef struct s_map {
	char	**map;
	int		w;
	int		h;

}				t_map;

typedef struct s_datas {
	t_map		*map;
	t_images	*img;
	void		*mlx;
	void		*win;
	int			status;
	int			pos_of_x;
	int			pos_of_y;
	int			nbr_of_collect;
	int			nbr_of_moves;
	bool		yes_exit;
}				t_datas;

// ERRORS //
int		ft_error(char c);
void	free_map(int i, char **map);
void	free_all(t_datas *d);
void	free_images(t_datas *d);

// CHECK_MAP //
int		same_lenght_and_exit(t_datas *d);
int		check_map(t_datas *datas);
int		is_wall_all_around(t_datas *datas);
void	count_map(t_map *map);

// CONVERT //
char	**convert_ber(char *lib);
char	*collect_strings(int fd);
int		check_char(char *strings_collected);
int		check_format_ber(char *str);
int		ft_strcmp_mod(char *s1, char *s2);

// INITIALISATION // 
int		parsing_map(t_datas *datas);
int		map_init(t_datas *datas);
int		init_images_1(t_datas *datas);
int		init_images_2(t_datas *datas);
void	nbr_of_collectible(t_datas *d);

// EVENT//
void	to_the_left(t_datas *datas);
void	to_the_right(t_datas *datas);
void	to_the_bottom(t_datas *datas);
void	to_the_top(t_datas *datas);
int		close_event(t_datas *datas);
int		key_event(int keycode, void *param);

#endif