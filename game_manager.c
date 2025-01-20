/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:32:09 by dario             #+#    #+#             */
/*   Updated: 2025/01/20 05:32:02 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_vars *vars)
{
	unsigned int	win_width;
	unsigned int	win_height;

	win_width = vars->map_properties->width * 32;
	win_height = vars->map_properties->height * 32;
	vars->mlx = mlx_init(win_width, win_height, "so_long", false);
	mlx_loop(vars->mlx);
}
