/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:08:45 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/02 09:56:29 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
* @warning MALLOC
*/
char	*ft_strdup(const char *source)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(source);
	dest = malloc (size * sizeof (char) + 1);
	if (!dest)
		return (NULL);
	ft_memcpy (dest, source, size);
	dest[size] = '\0';
	return (dest);
}
