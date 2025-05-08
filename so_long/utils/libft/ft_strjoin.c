/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:46:52 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/02 09:56:07 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
* @warning MALLOC
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		in1;
	int		in2;

	in1 = -1;
	in2 = -1;
	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s1 && !s2)
		return (ft_strdup (""));
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[++in1])
		new[in1] = s1[in1];
	while (s2[++in2])
	{
		new[in1] = s2[in2];
		in1++;
	}
	new[in1] = '\0';
	return (new);
}
