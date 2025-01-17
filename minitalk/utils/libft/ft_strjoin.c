/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42Madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:46:52 by afailde-          #+#    #+#             */
/*   Updated: 2024/04/15 18:18:49 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		in1;
	int		in2;

	in1 = 0;
	in2 = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[in1])
	{
		new[in1] = s1[in1];
		in1++;
	}
	while (s2[in2])
	{
		new[in1] = s2[in2];
		in1++;
		in2++;
	}
	new[in1] = '\0';
	return (new);
}
