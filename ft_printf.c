/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaya <shkaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:02:42 by shuntakaya        #+#    #+#             */
/*   Updated: 2024/05/11 11:45:31 by shkaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sep_specifiers(int c, va_list ap)
{
	int	print_chars;

	print_chars = 0;
	if (c == 'c')
		print_chars = my_printchar(va_arg(ap, int), 1);
	else if (c == 's')
		print_chars = my_printstr(va_arg(ap, char *), 1);
	else if (c == 'p')
		print_chars = my_printptr(va_arg(ap, unsigned long long), 1);
	else if (c == 'd' || c == 'i')
		print_chars = my_printnbr(va_arg(ap, int), 1);
	else if (c == 'u')
		print_chars = my_printunbr(va_arg(ap, unsigned int), 1);
	else if (c == 'x')
		print_chars = my_printhexa(va_arg(ap, unsigned int), 1, 1);
	else if (c == 'X')
		print_chars = my_printhexa(va_arg(ap, unsigned int), 0, 1);
	else if (c == '%')
		print_chars = my_printchar('%', 1);
	else
		return (-1);
	if (print_chars < 0)
		return (-1);
	return (print_chars);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		print_chars;
	int		tmp;

	print_chars = 0;
	va_start(ap, fmt);
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			tmp = sep_specifiers(fmt[++i], ap);
		else
			tmp = my_printchar(fmt[i], 1);
		if (0 <= tmp)
			print_chars += tmp;
		else
			return (-1);
		i++;
	}
	va_end(ap);
	return (print_chars);
}
