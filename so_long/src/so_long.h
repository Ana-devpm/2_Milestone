/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:40:18 by afailde-          #+#    #+#             */
/*   Updated: 2025/05/08 20:23:36 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define 	TILE_SIZE 64
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../utils/libft/libft.h"

//BOOL
typedef int		t_bool;
# define TRUE 0
# define FALSE 1

//		 ────────────── Player structure ──────────────
//		Contains the critical information of the player
typedef struct s_player
{
	mlx_image_t		*image;
	mlx_texture_t	*frame;
	int32_t			pos_x;
	int32_t			pos_y;
	int32_t			score;
	int				steps;
}	t_player;

typedef struct s_tile_text
{
	mlx_texture_t	*fence1;
	mlx_texture_t	*fence2;
	mlx_texture_t	*floor;
	
}	t_tile_text;

//		 ────────────── Collectible structure ──────────────
//		Contains the critical information of the collectibles
typedef struct s_collectible
{
	mlx_image_t		*image;
	mlx_texture_t	*frame;
	int32_t			pos_x;
	int32_t			pos_y;
	t_bool			used;
}	t_collectible;

//		 ────────────── Main game structure ──────────────
//		Contains the entire game state and logic references
typedef struct s_game
{
	int				w;				// Line width size in X direction (WIDTH)
	int				h;				// Line width size in Y direction (HEIGHT)
	char			**map;			// 2D array representing the game map
	mlx_t			*mlx;			// Structure MLX_CODAM
	t_player		player;			// Player
	t_collectible	*collect;		// Array for Collectibles.
	int				total_collect;	// Total number of collectibles. 
	
}	t_game;

//SOURCES FOR SO_LONG
t_bool			create_map(int fd, t_game *game);

//BUILDING MAP
t_bool			build_map(int fd, t_game *game);
t_bool			read_map(int fd, char **total_storage);
t_bool			check_total_storage(char *total_storage);

//PARSEC MAP FILES
t_bool		check_extension(int argc, char **argv);
t_bool		check_map(t_game *game);
t_bool		check_map_borders(t_game *game);
t_bool		check_characters(t_game *game);
t_bool		check_items(t_game *game);
t_bool		flood_fill(char **map, int x, int y);
t_bool		find_player(char **map, int *x, int *y);
t_bool		validate_path(t_game *game);
t_bool		validate_unreachable_items(char **dup_map);

//UTILS FOR MAP
char		**duplicate_map(t_game *game);
void		height_len(t_game *game);
int			count_letters(t_game *game, char character);
t_bool		find_collectible(char **map, t_game *game);

//CLEAN_UP
void		clean_up_player(t_game *game);
void 		clean_up_collectible(t_game *game);
void		clean_up_everything(t_game *game);

//WINDOW UTILS
t_bool 		init_mlx(t_game *game);


//PLAYER FILES
void 		ft_keys(void *param);
t_bool		initialize_player(t_game *game);
t_bool		load_textures(t_game *game);

//PLAYER MOVES
t_bool		move_up(t_game *game);
t_bool		move_down(t_game *game);
t_bool		move_left(t_game *game);
t_bool		move_right(t_game *game);

//COLLECTIBLES
int 		count_collectibles(char **map);
t_bool 		find_collectibles_in_map(char **map, t_collectible *collect, int *k);
t_bool		malloc_collectibles(t_game *game);
t_bool		load_collectible_textures(t_game *game);
t_bool 		initialize_collectibles(t_game *game);

#endif