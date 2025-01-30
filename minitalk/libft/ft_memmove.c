/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:13:58 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/19 12:43:49 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			i;
	char			ch_cpy;
	unsigned char	*dst;
	unsigned char	*sour;

	i = 0;
	ch_cpy = 1;
	dst = (unsigned char *) dest;
	sour = (unsigned char *) src;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		ch_cpy = -1;
		dst += num - 1;
		sour += num - 1;
	}
	while (i < num)
	{
		*dst = *sour;
		dst += ch_cpy;
		sour += ch_cpy;
		i++;
	}
	return (dest);
}
/* int main()
{
	overlapping case;
	char buffer[20] = "Hello word";

	printf("Buffer before the memmove: %s\n", buffer);
	
	ft_memmove (buffer + 3, buffer, 7);

	printf("Buffer after the memmove: %s\n", buffer);

	return (0); 

	normal case;

	char	dest[50] = "";
	char	source[50] = "Hello world";

	printf("Before the memmove: %s\n", dest);

	ft_memmove(dest, source, 6);

	printf("After the memmove: %s\n", dest);
	return(0);
}  */
