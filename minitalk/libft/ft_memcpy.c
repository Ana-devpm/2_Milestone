/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:49:16 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:57:47 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t				a;
	unsigned char		*finaldest;
	const unsigned char	*finalsrc;

	if (!dest && !src)
		return (0);
	a = 0;
	finaldest = (unsigned char *)dest;
	finalsrc = (const unsigned char *)src;
	while (a < num)
	{
		finaldest[a] = finalsrc[a];
		a++;
	}
	return (dest);
}
