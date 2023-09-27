/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 16:40:29 by salowie          ###   ########.fr       */
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

typedef struct s_im_struct {
	void	*xpm;
	int		w;
	int		h;

}				t_im_struct;

typedef struct s_images {
	t_im_struct	pony;
	t_im_struct	wall;
	t_im_struct	collect;
	t_im_struct	ground;
	t_im_struct	exit;
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
	int			pers_x;
	int			pers_y;
	int			nbr_of_collect;
	int			nbr_of_moves;
	int			collect_cpy;
	int			nbr_exit;
	bool		check_exit;
	bool		yes_exit;
}				t_datas;

// ERRORS //
int		ft_error(char c);
void	free_all(t_datas *d);
void	free_images(t_datas *d);
void	free_map(char **mappy);

// CHECK_MAP //
int		same_lenght(t_datas *d);
int		check_map(t_datas *datas);
int		is_wall_all_around(t_datas *datas);
int		is_exit_or_too_much(t_datas *d);
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
int		init_images(t_datas *datas);
int		nbr_of_collectible(t_datas *d);
void	init_variables(t_datas *datas);
void	images_placement(t_datas *d, int size_tile, int y, int x);

// EVENT//
void	to_the_left(t_datas *datas);
void	to_the_right(t_datas *datas);
void	to_the_bottom(t_datas *datas);
void	to_the_top(t_datas *datas);
void	where_is_p(t_datas *datas);
int		close_event(t_datas *datas);
int		key_event(int keycode, void *param);

// PATHFINDING //
void	dupmap_init(t_datas *datas);
void	where_is_exit(t_datas *datas);
void	find_exit(char **mappy, t_datas *d, int y, int x);

#endif