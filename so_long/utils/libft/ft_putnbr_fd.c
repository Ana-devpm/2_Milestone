/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42Madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:52:03 by afailde-          #+#    #+#             */
/*   Updated: 2024/06/04 15:10:45 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	numb;

	if (n >= 0)
		numb = n;
	else
	{
		numb = -n;
		write (fd, "-", 1);
	}
	if (numb >= 10)
	{
		ft_putnbr_fd(numb / 10, fd);
		ft_putchar_fd(numb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(numb + '0', fd);
}
