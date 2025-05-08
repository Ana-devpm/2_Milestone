/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_resize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:50:48 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 20:52:44 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool resize_collectible_image(t_game *game, int i)
{
	if (!mlx_resize_image(game->collect[i].image, TILE_SIZE, TILE_SIZE))
	{
		ft_printf("Error: couldn't resize image for collectible at index %d\n", i);
		return (FALSE);
	}
	return (TRUE);
}
