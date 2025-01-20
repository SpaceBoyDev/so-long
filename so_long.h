/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:13:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/20 21:33:55 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_map_properties
{
	char	**tiles;
	size_t	spawn_x;
	size_t	spawn_y;
	size_t	num_spawns;
	size_t	num_exits;
	size_t	num_objects;
	size_t	width;
	size_t	height;
}					t_map;

typedef struct s_flood_fill_data
{
	size_t	objects_count;
	bool	exit;
}					t_flood_data;

typedef struct s_game_vars
{
	mlx_t			*mlx;
	t_map			*map_properties;
	t_flood_data	*flood_data;
}					t_vars;

typedef struct s_tile
{
	char	character;
}					t_tile;

// main.c
void	init_struct_properties(t_vars *vars, t_map *map, t_flood_data *data);
// game_manager.c
void	start_game(t_vars *vars);

// file_check.c
void	check_file_validity(int fd, char *arg, t_map *map);
char	*check_file_extension(char *arg);
void	check_walls(t_map *map);

// map_checker.c
void	check_map_properties(t_map *map);
void	check_map(int fd, t_map *map);

// map_utils.c
char	**save_map(t_map *map, char *name, int fd);
void	fill_map(int fd, t_map *map);
char	**copy_map(char **map, int rows);
// flood_fill.c
void	flood_fill(char **map, t_flood_data *data, int x, int y);

// error_manager.c
char	*error_exit(char *error_message);
char	*error_exit_free(char *error_message, t_map *map);

//free_variables.c
char	*free_map_struct(t_map *map);
char	*free_map(char **map);
#endif