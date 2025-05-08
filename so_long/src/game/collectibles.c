/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:18:59 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 20:28:22 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_collectibles(char **map)
{
    int i;
    int j;
    int count;

	i = 0;
	count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

t_bool find_collectibles_in_map(char **map, t_collectible *collect, int *k)
{
	int i = 0;
	int j = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				collect[*k].pos_x = j;
				collect[*k].pos_y = i;
				collect[*k].used = FALSE;
				(*k)++;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	malloc_collectibles(t_game *game)
{
	int k;

	k = 0;
	game->total_collect = count_collectibles(game->map);
	game->collect = malloc(sizeof(t_collectible) * game->total_collect);
	if (!game->collect)
		return (FALSE);
	if (find_collectibles_in_map(game->map, game->collect, &k) == FALSE)
    {
        free(game->collect);
        return (FALSE);
    }
	return(TRUE);
}

t_bool	load_collectible_textures(t_game *game)
{
	int i;

	i = 0;
	while (i < game->total_collect)
	{
		game->collect[i].frame = mlx_load_png("sprites/collectible.png");
		if (!game->collect[i].frame)
		{
			ft_printf("Error: couldn't load texture for collectibles");
			return (FALSE);
		}
		game->collect[i].image = mlx_texture_to_image(game->mlx, game->collect[i].frame);
		if (!game->collect[i].image)
		{
			ft_printf("Error: couldn't load image for collectibles");
			return (FALSE);
		}
		mlx_image_to_window(game->mlx, game->collect[i].image,
            game->collect[i].pos_x * TILE_SIZE,
            game->collect[i].pos_y * TILE_SIZE);

		i++;
	}
	return (TRUE);
}

t_bool initialize_collectibles(t_game *game)
{
	if (malloc_collectibles(game) == FALSE)
	{
		clean_up_collectible(game);
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	if (load_collectible_textures(game) == FALSE)
	{
		clean_up_collectible(game);
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
