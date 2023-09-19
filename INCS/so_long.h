/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/19 18:45:23 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

// # include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_img_struct {
	void	*ptr_img;
	int		width;
	int		height;

}				t_img_struct;

void	*ft_error(void);
void	free_map(int i, char **map);
char	**convert_ber(char *lib);
char	*collect_strings(int fd);
int		check_map(char *strings_collected);
int		check_format_ber(char *str);
int		ft_strcmp_mod(char *s1, char *s2);

#endif