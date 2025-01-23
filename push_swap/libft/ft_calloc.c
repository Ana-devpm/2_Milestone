/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:09:37 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 11:40:03 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*ptr;

	if (items && size && items > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(items * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, items * size);
	return (ptr);
}
