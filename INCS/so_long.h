/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:12 by salowie           #+#    #+#             */
/*   Updated: 2023/09/14 13:53:52 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../../GET_NEXT_LINE/get_next_line.h"
#include "../../PRINTF/ft_printf.h"

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_img_struct {
	void	*ptr_img;
	int		width;
	int		height;

}				t_img_struct;

typedef struct	s_list
{
	char			*content;
	int				size;
	struct s_node	*next;
}				t_list;

void	*ft_error(void);
char	**convert_ber();
t_list	*collect_strings(int fd);

#endif