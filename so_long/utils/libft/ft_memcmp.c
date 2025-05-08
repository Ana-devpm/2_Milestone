/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:29:31 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:01:23 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t num)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (num == 0)
		return (0);
	ptr1 = (unsigned char *) string1;
	ptr2 = (unsigned char *) string2;
	while ((*ptr1 == *ptr2) && num -1 > 0)
	{
		ptr1++;
		ptr2++;
		num--;
	}
	return ((int)(*ptr1 - *ptr2));
}
