/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:14:22 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/11 11:30:05 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_printptr(unsigned long long ptr, int fd)
{
	int	print_chars;

	print_chars = 0;
	if (0 <= write (fd, "0x", 2))
		print_chars += 2;
	else
		return (-1);
	if (ptr == 0)
	{
		if (0 <= write (fd, "0", 1))
			print_chars += 1;
		else
			return (-1);
	}
	else
	{
		if (0 > my_put_hex(ptr, 1, fd))
			return (-1);
		print_chars += my_hex_len(ptr);
	}
	return (print_chars);
}
