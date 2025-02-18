/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:32:09 by dario             #+#    #+#             */
/*   Updated: 2025/02/18 19:01:59 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_vars *vars)
{
	unsigned int	win_width;
	unsigned int	win_height;

	win_width = vars->map->width * 16 * SCALE;
	win_height = vars->map->height * 16 * SCALE;
	vars->mlx = mlx_init(win_width, win_height, "so_long", false);
	draw_map(vars, vars->map->tiles);
	mlx_loop_hook(vars->mlx, &close_window_hook, vars);
	mlx_key_hook(vars->mlx, &player_input_hook, vars);
	mlx_loop(vars->mlx);
	ft_printf("Pos X -> %i", vars->player_x);
}

void	create_player(t_vars *vars, size_t x, size_t y)
{
	char	*file;

	file = "./textures/character.png";
	vars->player_img = image_to_window(vars->mlx, file, (t_vector){x, y}, 3);
	vars->player_x = x;
	vars->player_y = y;
	vars->player_objs = 0;
	vars->movement_count = 0;
}

void	collect_object(t_vars *vars, t_map *map, size_t x, size_t y)
{
	char	*end;

	end = "./textures/hole_ladder.png";
	++vars->player_objs;
	vars->map->tiles[y][x] = '0';
	image_to_window(vars->mlx, "./textures/ground.png", (t_vector){x, y}, 2);
	ft_printf(GREEN"Object collected!!\n"RST);
	ft_printf("You got %i/%i objects", vars->player_objs, vars->map->num_objs);
	ft_printf("\n");
	if (vars->player_objs >= vars->map->num_objs)
	{
		ft_printf(GREEN"All objects collected!!\n"RST);
		image_to_window(vars->mlx, end, (t_vector){map->end_x, map->end_y}, 2);
	}
}

void	end_game(t_vars *vars, bool has_won)
{
	if (has_won)
		ft_printf("\033[1;32m""----------\nYou Win!!\n----------\n""\033[0m");
	mlx_close_window(vars->mlx);
	free_vars(vars);
	mlx_terminate(vars->mlx);
	exit (0);
}
