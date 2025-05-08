/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:01:59 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 18:17:10 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	create_map(int fd, t_game *game)
{
	if (build_map(fd, game) == FALSE)
	{
		ft_printf("Error building map\n");
		return (FALSE);
	}
	height_len(game);
	if (!game->map)
	{
		ft_printf("Error: There isn't a map\n");
		return (FALSE);
	}
	if (check_map(game) == FALSE || check_map_borders(game) == FALSE
		|| check_map_borders(game) == FALSE || check_characters(game) == FALSE
		|| check_characters(game) == FALSE || check_items(game) == FALSE
		|| validate_path(game) == FALSE)
	{
		ft_printf("Error: you've made a mistake");
		return (FALSE);
	}
	return (TRUE);
}
