/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:44:36 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/20 12:27:18 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	index;

	index = 0;
	while ((index < num) && (s1[index] || s2[index]))
	{
		if (s1[index] != s2[index])
			return (((unsigned char) s1[index] - (unsigned char) s2[index]));
		index++;
	}
	return (0);
}
