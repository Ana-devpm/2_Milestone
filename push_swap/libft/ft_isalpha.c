/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:34:19 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 10:11:48 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if (character >= 'A' && character <= 'Z')
	{
		return (1);
	}
	else if (character >= 'a' && character <= 'z')
	{
		return (1);
	}
	return (0);
}
