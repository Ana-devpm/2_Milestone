/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:02:02 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 17:45:37 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_keys(void *param)
{
	t_game *game;

	game = (t_game *) param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	move_up(game);
	move_down(game);
	move_left(game);
	move_right(game);
}

t_bool	load_player_textures(t_game *game)
{
	game->player.frame = mlx_load_png("sprites/cow_cow.png");
	if (game->player.frame == NULL)
	{
		ft_printf("Error: Couldn't load texture for player\n");
		return (FALSE);
	}
	game->player.image = mlx_texture_to_image(game->mlx, game->player.frame);
	if (game->player.image == NULL || !mlx_resize_image(game->player.image, 80, 80))
	{
		ft_printf("Error: Couldn't create or resize player image\n");
		clean_up_player(game);
		return (FALSE);
	}
	return (TRUE);
}

t_bool initialize_player(t_game *game)
{
	if (load_player_textures(game) == FALSE)
	{

		clean_up_player(game);
		return (FALSE);
	}
	game->player.score = 0;
	game->player.steps = 0;
	return (TRUE);
}
