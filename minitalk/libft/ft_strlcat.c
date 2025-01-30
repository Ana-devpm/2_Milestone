/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:53:11 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:14:41 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t numb)
{
	size_t	source;
	size_t	final_dest;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dest && numb == 0)
		return (si);
	final_dest = ft_strlen (dest);
	di = final_dest;
	if (numb <= di)
		return (numb + si);
	source = 0;
	while (src[source] && final_dest + 1 < numb)
	{
		dest[final_dest] = src[source];
		source++;
		final_dest++;
	}
	dest[final_dest] = 0;
	return (di + si);
}
