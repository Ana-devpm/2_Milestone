/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:11:32 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:17:51 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *a, int character)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	while (i >= 0)
	{
		if (a[i] == (char)character)
			return ((char *)(a + i));
		i--;
	}
	return (0);
}
