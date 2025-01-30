/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:48:23 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/18 09:26:20 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	index;
	size_t	save_words;

	index = 0;
	save_words = 0;
	while (str[index] != '\0')
	{
		while (str[index] == c)
			index++;
		while (str[index] != c && str[index] != '\0')
		{
			index++;
			if (str[index] == c || str[index] == '\0')
				save_words++;
		}
	}
	return (save_words);
}

static char	**free_container(int i, char **container)
{
	while (i >= 0)
	{
		free(container[i--]);
	}
	free(container);
	return (NULL);
}

static char	**fill_container(const char *s, char c, char **container)
{
	int	index;
	int	start;
	int	position;

	index = 0;
	position = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		start = index;
		while (s[index] != c && s[index] != '\0')
		{
			index++;
			if (s[index] == c || s[index] == '\0')
			{
				container[position] = ft_substr(s, start, index - start);
				if (!container[position])
					return (free_container(position, container));
				position++;
			}
		}
	}
	return (container);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**container;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	container = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!container)
		return (NULL);
	return (fill_container(s, c, container));
}
