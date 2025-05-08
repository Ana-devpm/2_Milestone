/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:17:19 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/26 15:45:34 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	check_extension(int argc, char **argv)
{
	const char	*filename;
	size_t		len;

	(void)argc;
	filename = argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(ft_strchr(filename, '.'), ".ber", 4) != 0)
	{
		ft_printf("Error: invalid map extension\n");
		return (FALSE);
	}
	return (TRUE);
}
