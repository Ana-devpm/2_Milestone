/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:17:41 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:10:32 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t numb)
{
	size_t	a;

	if ((!dest || !src) && numb == 0)
		return (0);
	a = 0;
	if (numb != 0)
	{
		while (src[a] != '\0' && a < (numb -1))
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (ft_strlen(src));
}
