/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salowie <salowie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:03:44 by salowie           #+#    #+#             */
/*   Updated: 2023/05/05 09:52:58 by salowie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr(int n);
int		ft_unsigned_putnbr(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_hexa(unsigned int n, char c);
int		ft_print_ptr(uintptr_t ptr);
int		ft_put_ptr(uintptr_t ptr);
int		check_type(char c, va_list arg);
int		is_type(char c);
int		ft_printf(const char *type, ...);

#endif