/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42Madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:20:50 by afailde-          #+#    #+#             */
/*   Updated: 2024/09/05 14:31:59 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int			ft_putchar(char c, int *index);
int			ft_printf(const char *format, ...);
int			ft_puthex(unsigned long n, char format, int *index);
int			ft_pointer_direction(void *ptr, char format, int *index);
void		ft_putnbr(int n, int *index);
void		ft_putstr(char *s, int *index);
void		ft_nbr_unsigned(unsigned int n, int *index);

#endif
