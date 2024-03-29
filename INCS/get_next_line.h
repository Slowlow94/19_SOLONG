/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sarah <Sarah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:47:24 by salowie           #+#    #+#             */
/*   Updated: 2023/09/14 18:17:07 by Sarah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# elif BUFFER_SIZE > 1000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_free(char **str);
char	*ft_keep_left(char *str);
char	*ft_keep_right(char *str);
char	*ft_read(int fd, char *keep_str, char *temp);

#endif