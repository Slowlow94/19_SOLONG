/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/21 18:49:38 by salowie          ###   ########.fr       */
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
}				t_datas;

// ERRORS //
int		ft_error(char c);
void	free_map(int i, char **map);

// CONVERT //
char	**convert_ber(char *lib);
char	*collect_strings(int fd);
int		check_map(char *strings_collected);
int		check_format_ber(char *str);
int		ft_strcmp_mod(char *s1, char *s2);

// INITIALISATION // 
void	count_map(t_map *map);
int		parsing_map(t_datas *datas);
int		map_init(t_datas *datas);
int		init_images(t_datas *datas);

// MOVES //
void	to_the_left(t_datas *datas);
void	to_the_right(t_datas *datas);
void	to_the_bottom(t_datas *datas);
void	to_the_top(t_datas *datas);

#endif