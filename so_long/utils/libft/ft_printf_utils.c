/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:55:33 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/21 19:23:46 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s, int *index)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		(*index)++;
		i++;
	}
}

void	ft_putnbr(int n, int *index)
{
	unsigned int	numb;

	if (n >= 0)
		numb = n;
	else
	{
		numb = -n;
		ft_putchar('-', index);
	}
	if (numb >= 10)
	{
		ft_putnbr(numb / 10, index);
		ft_putchar((numb % 10 + '0'), index);
	}
	else
		ft_putchar((numb + '0'), index);
}

int	ft_puthex(unsigned long n, char format, int *index)
{
	int				i;
	char			*base;
	unsigned int	base_length;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	base_length = 16;
	if (n > (base_length -1))
		i += ft_puthex(n / base_length, format, index);
	i += ft_putchar(*(base + (n % base_length)), index);
	return (i);
}

void	ft_nbr_unsigned(unsigned int n, int *index)
{
	if (n >= 10)
		ft_nbr_unsigned(n / 10, index);
	ft_putchar(((n % 10) + '0'), index);
}

int	ft_pointer_direction(void *ptr, char format, int *index)
{
	if (!ptr)
	{
		ft_putstr("(nil)", index);
		return (-1);
	}
	ft_putstr("0x", index);
	ft_puthex((unsigned long) ptr, format, index);
	return (0);
}
