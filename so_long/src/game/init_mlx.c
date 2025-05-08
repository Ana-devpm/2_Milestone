/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:06:57 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 20:29:37 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_game *game)
{
	if (initialize_player(game) == FALSE)
		mlx_terminate(game->mlx);
	if (mlx_image_to_window(game->mlx, game->player.image,
		game->player.pos_x * TILE_SIZE, game->player.pos_y * TILE_SIZE) == -1)
		mlx_terminate(game->mlx);
}
t_bool init_mlx(t_game *game)
{
	ft_printf("game->w = %d, game->h = %d\n", game->w, game->h);
	game->mlx = mlx_init(game->w * TILE_SIZE, game->h * TILE_SIZE, "so_long", true);
	if (!game->mlx)
	{
		ft_printf("Error: couldn't load window");
		return (FALSE);
	}
	init_player(game);
	initialize_collectibles(game);
	mlx_loop_hook(game->mlx, ft_keys, game);
	mlx_loop(game->mlx);
	clean_up_everything(game);
	mlx_terminate(game->mlx);
	return (TRUE);
}
