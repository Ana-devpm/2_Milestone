/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:09:37 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/17 16:47:37 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t len)
{
	void	*ptr;

	if (count && len && count > (SIZE_MAX / len))
		return (NULL);
	ptr = malloc(count * len);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, count * len);
	return (ptr);
}
