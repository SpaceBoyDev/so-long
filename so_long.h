/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:13:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/02/12 19:51:20 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# ifndef SCALE
#  define SCALE 3
# endif

typedef struct s_map
{
	char	**tiles;
	size_t	spawn_x;
	size_t	spawn_y;
	size_t	end_x;
	size_t	end_y;
	size_t	num_spawns;
	size_t	num_exits;
	size_t	num_objs;
	size_t	width;
	size_t	height;
}					t_map;

typedef struct s_flood_data
{
	size_t	objects_count;
	bool	exit;
}					t_flood_data;

typedef struct s_vars
{
	mlx_t			*mlx;
	t_map			*map;
	t_flood_data	*flood_data;
	size_t			movement_count;
	mlx_image_t		*player_img;
	size_t			player_x;
	size_t			player_y;
	size_t			player_objs;
}					t_vars;

typedef struct s_vector
{
	size_t		x;
	size_t		y;
}					t_vector;

// main.c
void		init_structs(t_vars *vars, t_map *map, t_flood_data *data);

// game_manager.c
void		start_game(t_vars *vars);
void		create_player(t_vars *vars, size_t x, size_t y);
void		collect_object(t_vars *vars, t_map *map, size_t x, size_t y);
void		end_game(t_vars *vars, bool has_won);
// image_manager.c
mlx_image_t	*image_to_window(mlx_t *mlx, char *file, t_vector pos, int depth);
char		*draw_map(t_vars *vars, char **map);
char		*draw_map_misc(t_vars *vars, char **map, char *obj, char *hole);
// player_movement.c
void		move_player(t_vars *vars, size_t x, size_t y);

// hooks.c
void		close_window_hook(void *param);
void		player_input_hook(mlx_key_data_t keydata, void *param);

// file_check.c
void		check_file_validity(int fd, char *arg, t_map *map);
char		*check_file_extension(char *arg);
void		check_walls(t_map *map);

// map_checker.c
void		check_map_properties(t_map *map);
void		check_map(int fd, t_map *map);

// map_utils.c
char		**save_map(t_map *map, char *name, int fd);
void		fill_map(int fd, t_map *map);
char		**copy_map(char **map, int rows);

// flood_fill.c
void		flood_fill(char **map, t_flood_data *data, int x, int y);

//free_variables.c
char		*free_vars(t_vars *vars);
char		*free_map_struct(t_map *map);
char		*free_map(char **map);

// error_manager.c
char		*error_exit(char *error_message);
char		*error_exit_free(char *error_message, t_map *map);

#endif