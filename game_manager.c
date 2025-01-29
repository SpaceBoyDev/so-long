/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:32:09 by dario             #+#    #+#             */
/*   Updated: 2025/01/29 19:12:58 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_vars *vars)
{
	unsigned int	win_width;
	unsigned int	win_height;

	win_width = vars->map_properties->width * 16 * SCALE;
	win_height = vars->map_properties->height * 16 * SCALE;
	vars->mlx = mlx_init(win_width, win_height, "so_long", false);
	draw_map(vars, vars->map_properties->tiles);
	mlx_loop_hook(vars->mlx, &close_window_hook, vars);
	mlx_key_hook(vars->mlx, &player_input_hook, vars);
	mlx_loop(vars->mlx);
	ft_printf("Pos X -> %i", vars->player_x);
}

void	create_player(t_vars *vars, size_t x, size_t y)
{
	char	*file;

	file = "./textures/character.png";
	vars->player_img = image_to_window(vars->mlx, file, x, y, 3);
	vars->player_x = x;
	vars->player_y = y;
	vars->player_objects = 0;
	vars->movement_count = 0;
}
