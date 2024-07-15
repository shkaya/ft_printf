/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:15:43 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/11 11:28:44 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_put_nbr(int c, int fd)
{
	long	ln;
	char	digit;

	ln = (long)c;
	if (ln < 0)
	{
		if (0 > write(fd, "-", 1))
			return (-1);
		ln = -ln;
	}
	if (ln >= 10)
		my_put_nbr(ln / 10, fd);
	digit = '0' + (ln % 10);
	if (0 > write(fd, &digit, 1))
		return (-1);
	return (0);
}

static int	my_nbr_len(int c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c /= 10;
		count++;
	}
	return (count);
}

int	my_printnbr(int c, int fd)
{
	int	print_chars;

	print_chars = 0;
	if (0 > my_put_nbr(c, fd))
		return (-1);
	print_chars += my_nbr_len(c);
	if (c < 0)
		print_chars++;
	return (print_chars);
}
