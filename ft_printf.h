/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuntakaya <shuntakaya@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:03:12 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/10 19:01:20 by shuntakaya       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	my_printchar(int c, int fd);
int	my_printstr(char *s, int fd);
int	my_printptr(unsigned long long ptr, int fd);
int	my_printnbr(int c, int fd);
int	my_printunbr(unsigned int c, int fd);
int	my_put_hex(unsigned long long ptr, int is_lower, int fd);
int	my_hex_len(unsigned long long ptr);
int	my_printhexa(unsigned int c, int is_lower, int fd);

#endif