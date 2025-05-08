/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:39:09 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 18:38:14 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_letters(t_game *game, char character)
{
	int	x;
	int	y;
	int	counter;

	y = 0;
	counter = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == character)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

void	height_len(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->h = i;
}



// t_bool	find_exit(char **map, t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'E')
// 			{
// 				game->collect.pos_x = j;
// 				game->collect.pos_y = i;
// 				return (TRUE);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (FALSE);
// }
