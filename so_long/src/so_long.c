/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:40:04 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/05 10:24:41 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
	{
		ft_printf("I need: ./so_long and (map_name).ber\n");
		return (1);
	}
	if (check_extension(argc, argv) == FALSE)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: invalid map\n");
		return (1);
	}
	if (create_map(fd, &game) == FALSE)
		return (1);
	init_mlx(&game);
	ft_free_array(game.map);
	return (0);
}
