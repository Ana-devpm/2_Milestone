/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:26:54 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/20 12:24:56 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*dest;
	unsigned int	length;

	if (!s || !f)
		return (0);
	index = 0;
	length = ft_strlen(s);
	dest = ft_strdup(s);
	if (!dest)
		return (NULL);
	while (index < length)
	{
		dest[index] = f(index, s[index]);
		index++;
	}
	return (dest);
}
