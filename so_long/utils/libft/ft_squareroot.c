/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squareroot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:48:42 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/17 13:47:56 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_squareroot(int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
