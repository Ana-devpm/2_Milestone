/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:39:36 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/17 12:21:06 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *a, int character)
{
	if (!a)
		return (0);
	while ((char) character != *a)
	{
		if (!*a)
			return (0);
		a++;
	}
	return ((char *)a);
}
