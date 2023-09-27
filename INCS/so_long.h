/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/27 19:24:53 by salowie          ###   ########.fr       */
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

# define ERROR_FILE "Smalleh, ERROR !\nCause : wrong format of text file\n"
# define ERROR_IMG "Smalleh, ERROR !\nCause : image can't download\n"
# define ERROR_MLX "Smalleh, ERROR !\nCause : the MinilibX is crashed\n"
# define ERROR_WIN "Smalleh, ERROR !\nCause : the window is crashed\n"
# define ERROR_MAP "Smalleh, ERROR !\nCause : invalide map bitch\n"
# define ERROR_ARG "Smalleh, ERROR !\nCause : Wrong number of arguments\n"
# define ERROR_FD "Smalleh, ERROR !\nCause : opening of fd failed\n"
# define ERROR_NO_EXIT "Smalleh, ERROR !\nCause : no exit\n"
# define ERROR_TOO_EXIT "Smalleh, ERROR !\nCause : too much exit\n"
# define ERROR_COLLECT "Smalleh, ERROR !\nCause : no collectible to collect\n"
# define ERROR_PATH "Smalleh, ERROR !\nCause : no path to the exit\n"
# define ERROR_P "Smalleh, ERROR !\nCause : too much player for this game\n"

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
	int			nbr_of_player;	
	int			collect_cpy;
	int			nbr_exit;
	bool		check_exit;
	bool		yes_exit;
	bool		is_exit;
}				t_datas;

// ERRORS //
void	ft_error(char *error_msg, t_datas *datas);
void	free_all(t_datas *d);
void	free_images(t_datas *d);
void	free_map(char **mappy);

// CHECK_MAP //
int		same_lenght(t_datas *d);
int		check_map(t_datas *datas);
int		is_wall_all_around(t_datas *datas);
int		is_exit_or_too_much(t_datas *d);
int		nbr_of_player(t_datas *d);
void	count_map(t_map *map);

// CONVERT //
char	**convert_ber(char *lib, t_datas *datas);
char	*collect_strings(int fd);
int		check_char(char *strings_collected);
int		check_format_ber(char *str);
int		ft_strcmp_mod(char *s1, char *s2);

// INITIALISATION //
int		parsing_map(t_datas *datas);
int		map_init(t_datas *datas);
int		init_images(t_datas *datas);
int		nbr_of_collectible(t_datas *d);
void	init_variables(t_datas *datas, char *lib);
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