/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:54:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/02/08 20:49:47 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_anim(t_vars *vars, int delta_x, int delta_y)
{
	mlx_texture_t	*texture;
	int				scale_multi;

	scale_multi = 16 * SCALE;
	texture = mlx_load_png("textures/character_left.png");
	if (!texture)
		return (NULL);
	vars->player_img = mlx_texture_to_image(vars->mlx, texture);
}


void	move_player(t_vars *vars, size_t x, size_t y)
{
	int	delta_x;
	int	delta_y;

	if (!vars->map->tiles[y][x]
		|| vars->map->tiles[y][x] == '1')
		return ;
	if (vars->map->tiles[y][x] == 'C')
		collect_object(vars, vars->map, x, y);
	delta_x = vars->player_x - x;
	delta_y = vars->player_y - y;
	vars->player_img->instances[0].x -= 16 * SCALE * delta_x;
	vars->player_img->instances[0].y -= 16 * SCALE * delta_y;
	vars->player_x = x;
	vars->player_y = y;
	++vars->movement_count;
	// player_anim(vars, delta_x, delta_y);
	ft_printf("Movement count -> %i\n", vars->movement_count);
	if (vars->map->tiles[y][x] == 'E'
		&& vars->player_objs == vars->map->num_objs)
		end_game(vars, true);
}
