/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:56:25 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/26 15:04:42 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	check_total_storage(char *total_storage)
{
	int	i;

	if (total_storage[0] == '\n')
		return (FALSE);
	i = 0;
	while (total_storage[i])
	{
		if (total_storage[i] == '\n' && total_storage[i + 1] == '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	read_map(int fd, char **total_storage)
{
	char	*line;
	char	*temp;

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		temp = *total_storage;
		*total_storage = ft_strjoin(*total_storage, line);
		if (!*total_storage)
			return (free (temp), free(line), FALSE);
		free(temp);
		temp = NULL;
		free (line);
	}
	return (TRUE);
}

t_bool	build_map(int fd, t_game *game)
{
	char	*total_storage;

	total_storage = ft_strdup("");
	if (read_map(fd, &total_storage) == FALSE
		|| check_total_storage(total_storage) == FALSE)
	{
		free(total_storage);
		return (FALSE);
	}
	game->map = ft_split(total_storage, '\n');
	free (total_storage);
	if (!game->map)
		return (FALSE);
	return (TRUE);
}
