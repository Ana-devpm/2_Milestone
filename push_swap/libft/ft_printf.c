/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:20:45 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/21 19:18:09 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int *index)
{
	write(1, &c, 1);
	(*index)++;
	return (1);
}

void	ft_id_placeholder(char format, va_list args, int *index)
{
	if (format == 'c')
		(ft_putchar(va_arg(args, int), index));
	else if (format == 's')
		ft_putstr(va_arg(args, char *), index);
	else if (format == 'p')
		(ft_pointer_direction(va_arg(args, void *), format, index));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), index);
	else if (format == 'u')
		(ft_nbr_unsigned(va_arg(args, unsigned int), index));
	else if (format == 'x' || format == 'X')
		(ft_puthex(va_arg(args, unsigned int), format, index));
	else if (format == '%')
		(ft_putchar('%', index));
}

/**
 * Print Format allows us to imprint. Itera caracter a caracter hasta que
 * termina la cadena.
 * @param format
 * @param ... are the undefined arguments. 
  */

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_printed_char;
	va_list	args;

	va_start(args, format);
	total_printed_char = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_id_placeholder(format[i], args, &total_printed_char);
		}
		else
		{
			ft_putchar(format[i], &total_printed_char);
		}
		i++;
	}
	va_end(args);
	return (total_printed_char);
}
