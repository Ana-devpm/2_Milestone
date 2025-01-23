/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:18:16 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:12:08 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if ((alnum >= 'A' && alnum <= 'Z') || (alnum >= 'a' && alnum <= 'z'))
	{
		return (1);
	}
	else if (alnum >= '0' && alnum <= '9')
	{
		return (1);
	}
	return (0);
}
