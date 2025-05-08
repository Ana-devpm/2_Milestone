/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_graphics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:44:14 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 20:19:25 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_up_player(t_game *game)
{
	if (game->player.frame != NULL)
		mlx_delete_texture(game->player.frame);
	if (game->player.image != NULL)
		mlx_delete_image(game->mlx, game->player.image);
}

void clean_up_collectible(t_game *game)
{
	int i = 0;
    while (i < game->total_collect)
    {
        if (game->collect[i].image)
            mlx_delete_image(game->mlx, game->collect[i].image);
        i++;
    }
    if (game->collect)
    {
        free(game->collect);
        game->collect = NULL;
    }	
}
void	clean_up_everything(t_game *game)
{
	clean_up_player(game);
	clean_up_collectible(game);
}
