/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:22:56 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 15:45:14 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	move_up(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		game->player.image->instances[0].y -= TILE_SIZE;
		game->player.pos_y -= 1;
		game->player.steps++;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	move_down(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		game->player.image->instances[0].y += TILE_SIZE;
		game->player.pos_y += 1;
		game->player.steps++;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	move_left(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player.image->instances[0].x -= TILE_SIZE;
		game->player.pos_x -= 1;
		game->player.steps++;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	move_right(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player.image->instances[0].x += TILE_SIZE;
		game->player.pos_x += 1;
		game->player.steps++;
		return (TRUE);
	}
	return (FALSE);
}
