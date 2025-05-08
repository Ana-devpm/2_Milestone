/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:08:09 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 21:30:53 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	render_floor_tiles(t_game *game)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			game->tiles[index].frame = game->tiles[0].frame;
			game->tiles[index].image = mlx_texture_to_image(game->mlx, game->tiles[index].frame);
			if (!game->tiles[index].image ||
				!mlx_resize_image(game->tiles[index].image, TILE_SIZE, TILE_SIZE))
				return (FALSE);
			game->tiles[index].pos_x = j;
			game->tiles[index].pos_y = i;
			mlx_image_to_window(game->mlx, game->tiles[index].image, j * TILE_SIZE, i * TILE_SIZE);
			index++;
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	draw_floor(t_game *game)
{
	game->tiles = malloc(sizeof(t_tile_text) * game->w * game->h);
	if (!game->tiles)
		return (FALSE);
	game->tiles[0].frame = mlx_load_png("sprites/grass_long.png");
	if (!game->tiles[0].frame)
	{
		ft_printf("Error: couldn't load floor texture\n");
		free(game->tiles);
		return (FALSE);
	}
	if (render_floor_tiles(game) ==  FALSE)
	{
		mlx_delete_texture(game->tiles[0].frame);
		free(game->tiles);
		return (FALSE);
	}
	mlx_delete_texture(game->tiles[0].frame);
	return (TRUE);
}

t_bool	initialize_floor(t_game *game)
{
	if (draw_floor(game) == FALSE)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
