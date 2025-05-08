/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:43:59 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:05:26 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int character, size_t num)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		if (((unsigned char *)s)[index] == (unsigned char)character)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}
