/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:17:43 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:55:39 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t c)
{
	unsigned char	*d;
	unsigned char	value;

	d = a;
	value = (unsigned char)b;
	while (c--)
	{
		*d++ = value;
	}
	return (a);
}
