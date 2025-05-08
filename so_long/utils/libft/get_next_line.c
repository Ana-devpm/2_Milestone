/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:57:25 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/15 12:56:32 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** This function allows us to know if rest_storage has something to read. 
 * @param fd the fd descriptor we need to read.
 * @param rest_storage where we are going to storage the content of the fd.
 * @return rest_storage.
 */

static char	*read_storage(int fd, char *rest_storage)
{
	ssize_t	read_bytes;
	char	*temp;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rest_storage), NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		if (ft_strchr(rest_storage, '\n'))
			return (free(buffer), rest_storage);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free (rest_storage), NULL);
		if (read_bytes == 0)
			return (free(buffer), rest_storage);
		buffer[read_bytes] = '\0';
		temp = rest_storage;
		rest_storage = ft_strjoin(rest_storage, buffer);
		free (temp);
		if (!rest_storage)
			return (free(buffer), NULL);
	}
	return (free(buffer), rest_storage);
}

/** This function allow us to extract the line till finds '\n'
* character
* @param rest_storage this is our storage, where we'll save the 
* rest content. 
* @return the new line.
*/
static char	*extract_line(char	**rest_storage)
{
	char	*new_line;
	char	*pos;
	char	*temp;

	if (!(*rest_storage)[0])
		return (NULL);
	pos = ft_strchr(*rest_storage, '\n');
	if (!pos)
	{
		temp = ft_strdup(*rest_storage);
		free (*rest_storage);
		*rest_storage = NULL;
		return (temp);
	}
	new_line = malloc(sizeof(char) * (pos - *rest_storage + 2));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, *rest_storage, pos - *rest_storage + 2);
	++pos;
	temp = *rest_storage;
	*rest_storage = ft_strdup(pos);
	free(temp);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*rest_storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_storage = read_storage(fd, rest_storage);
	if (!rest_storage)
		return (free(rest_storage), rest_storage = NULL, NULL);
	if (rest_storage != NULL)
	{
		line = extract_line(&rest_storage);
		if (!line)
			return (free(rest_storage), rest_storage = NULL, NULL);
		return (line);
	}
	free(rest_storage);
	rest_storage = NULL;
	return (NULL);
}
