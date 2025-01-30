/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:08:45 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:22:31 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
