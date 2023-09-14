/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/14 18:03:46 by Sarah            ###   ########.fr       */
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
char	**convert_ber(void);
t_list	*collect_strings(int fd);
char	**fill_map(t_list *strings_collected);

#endif