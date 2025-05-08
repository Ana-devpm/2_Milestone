/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:41:54 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 18:38:37 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**duplicate_map(t_game *game)
{
	int		y;
	char	**dup_map;

	dup_map = (char **)malloc(sizeof(char *) * (game->h +1));
	if (!dup_map)
	{
		ft_free_array(dup_map);
		return (ft_free_array(game->map), NULL);
	}
	y = 0;
	while (y < game->h)
	{
		(dup_map)[y] = ft_strdup(game->map[y]);
		if (!(dup_map)[y])
		{
			ft_free_array(dup_map);
			return (ft_free_array(game->map), NULL);
		}
		y++;
	}
	(dup_map)[y] = NULL;
	return (dup_map);
}

t_bool	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool	validate_unreachable_items(char **dup_map)
{
	int	i;
	int	j;

	i = 0;
	while (dup_map[i])
	{
		j = 0;
		while (dup_map[i][j])
		{
			if (dup_map[i][j] == 'C' || dup_map[i][j] == 'E')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	validate_path(t_game *game)
{
	char	**dup_map;
	int		x;
	int		y;

	dup_map = duplicate_map(game);
	if (!dup_map)
		return (ft_free_array(game->map), ft_free_array(dup_map), FALSE);
	if (find_player(dup_map, &x, &y) == FALSE
		|| flood_fill(dup_map, x, y) == FALSE
		|| validate_unreachable_items(dup_map) == FALSE)
	{
		ft_free_array(dup_map);
		ft_free_array(game->map);
		ft_printf("Error: The map is unsolvable\n");
		return (FALSE);
	}
	game->player.pos_x = x;
	game->player.pos_y = y;
	ft_free_array(dup_map);
	return (TRUE);
}
