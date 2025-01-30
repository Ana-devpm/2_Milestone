/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:07:17 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:27:38 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sb_str, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (sb_str[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (((i + j) < len) && (str[i + j] == sb_str[j])
			&& (sb_str[j] != '\0'))
			j++;
		if (sb_str[j] == '\0')
			return ((char *)&str[i]);
		i++;
		j = 0;
	}
	return (0);
}
