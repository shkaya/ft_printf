/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:21:54 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/11 11:32:09 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_put_hex(unsigned long long ptr, int is_lower, int fd)
{
	char	c;

	if (16 <= ptr)
	{
		if (0 > my_put_hex(ptr / 16, is_lower, fd)
			|| 0 > my_put_hex(ptr % 16, is_lower, fd))
			return (-1);
	}
	else
	{
		if (ptr <= 9)
			c = ptr + '0';
		else
		{
			if (is_lower)
				c = (ptr - 10) + 'a';
			else
				c = (ptr - 10) + 'A';
		}
		return (my_printchar(c, fd));
	}
	return (0);
}

int	my_hex_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

int	my_printhexa(unsigned int c, int is_lower, int fd)
{
	int	print_cahrs;

	print_cahrs = 0;
	if (0 > my_put_hex(c, is_lower, fd))
		return (-1);
	print_cahrs = my_hex_len(c);
	return (print_cahrs);
}
