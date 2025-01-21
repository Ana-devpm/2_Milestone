/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:08:11 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/20 17:33:32 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "utils/ft_printf/ft_printf.h"

typedef struct s_bit_buffer
{
	int	byte;
	int	bit;
}		t_bit_buffer;

int	ft_isdigit(int num);
int	ft_atoi(const char *str);

#endif