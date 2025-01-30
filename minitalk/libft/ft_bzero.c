/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:07:46 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:03:21 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *a, size_t b)
{
	size_t	length;
	char	*str;

	str = a;
	length = 0;
	while (length < b)
	{
		str[length] = 0;
		length++;
	}
}
