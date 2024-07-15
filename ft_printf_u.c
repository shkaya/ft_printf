/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:20:43 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/11 11:39:07 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_put_unbr(unsigned int c, int fd)
{
	char	digit;
	int		print_chars;

	print_chars = 0;
	if (c >= 10)
		print_chars += my_put_unbr(c / 10, fd);
	digit = '0' + (c % 10);
	if (0 > write(fd, &digit, 1))
		return (-1);
	return (print_chars + 1);
}

int	my_printunbr(unsigned int c, int fd)
{
	int	print_chars;

	print_chars = 0;
	print_chars += my_put_unbr(c, fd);
	if (0 > print_chars)
		return (-1);
	return (print_chars);
}
