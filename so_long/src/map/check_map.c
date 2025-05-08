/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:49:08 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/26 15:37:58 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
* This functions checks that this have thigns inside and 
* the map it's a rectangle.
*/
t_bool	check_map(t_game *game)
{
	int	i;

	i = 0;
	game->w = ft_strlen(game->map[0]);
	if (!game->map || !game->map[0] || !game->map[0][0])
	{
		ft_printf("Error: there's something wrong with your map\n");
		return (ft_free_array(game->map), FALSE);
	}
	while (game->map[i])
	{
		if (!game->map[i + 1])
			return (TRUE);
		if (game->w != ft_strlen(game->map[i + 1]))
		{
			ft_printf("Error: The map is not rectangular\n");
			return (ft_free_array(game->map), FALSE);
		}
		i++;
	}
	return (TRUE);
}

/*
* Check the map borders.
*/
t_bool	check_map_borders(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
			{
				ft_printf("BORDERS NOT CLOSED\n");
				return (ft_free_array(game->map), FALSE);
			}
			if ((y == game->h - 1 || x == game->w - 1)
				&& game->map[y][x] != '1')
			{
				ft_printf("BORDERS NOT CLOSED\n");
				return (ft_free_array(game->map), FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

/**
 * Check if there's a extrange character.
 */
t_bool	check_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
			&& game->map[y][x] != 'E' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'C')
			{
				ft_printf("Error: There's a extrange character in your map\n");
				return (ft_free_array(game->map), FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

/*
* Check if there's 1P, 1E and at least 1C.
*/
t_bool	check_items(t_game *game)
{
	int	player;
	int	colect;
	int	exit;

	player = count_letters(game, 'P');
	colect = count_letters(game, 'C');
	exit = count_letters(game, 'E');
	if (player != 1)
	{
		ft_printf("Error: There's more than 1 player\n");
		return (ft_free_array(game->map), FALSE);
	}
	if (colect < 1)
	{
		ft_printf("Error: There's not enough colectables\n");
		return (ft_free_array(game->map), FALSE);
	}
	if (exit != 1)
	{
		ft_printf("Error: There's more than 1 exit\n");
		return (ft_free_array(game->map), FALSE);
	}
	return (TRUE);
}
