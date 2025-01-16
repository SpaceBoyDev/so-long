/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:13:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/16 20:24:50 by dario            ###   ########.fr       */
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
	char	*name;
	char	**tiles;
	size_t	player_x;
	size_t	player_y;
	size_t	num_spawns;
	size_t	num_exits;
	size_t	num_objects;
	size_t	width;
	size_t	height;
}					t_map_properties;

typedef struct s_flood_fill_data
{
	size_t	objects_count;
	bool	exit;
}					t_flood_fill_data;

typedef struct s_game_vars
{
	mlx_t				*mlx;
	t_map_properties	*map_properties;
	t_flood_fill_data	*flood_data;
}					t_game_vars;

typedef struct s_tile
{
	char	character;
}					t_tile;

// main.c
void	init_map_properties(t_map_properties *map_properties);
char	**copy_map(t_map_properties *map, int fd);

// game_manager.c
void	start_game(t_game_vars *vars);

// file_check.c
void	check_file_validity(int fd, char *arg, t_map_properties *map);
char	*check_file_extension(char *arg);
void	check_walls(t_map_properties *map);

// map_manager.c
void	check_map_properties(t_map_properties *map);
void	check_map(int fd, t_map_properties *map);

// error_manager.c
void	error_exit(char *error_message);
#endif