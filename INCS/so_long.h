/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/20 17:52:22 by salowie          ###   ########.fr       */
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

typedef struct s_struct {
	void	*ptr;
	int		width;
	int		height;

}				t_struct;

typedef struct s_map {
	int		width;
	int		height;

}				t_map;

// ERRORS //
void	*ft_error(void);
void	free_map(int i, char **map);

// CONVERT //
char	**convert_ber(char *lib);
char	*collect_strings(int fd);
int		check_map(char *strings_collected);
int		check_format_ber(char *str);
int		ft_strcmp_mod(char *s1, char *s2);

// INITIALISATION // 
t_map	count_map(char **map);
int		images_init(void *mlx, void *window, char **map, t_map *map_size);
void	map_init(char **map, t_map *map_size);

#endif