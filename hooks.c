/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:25:20 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/29 19:11:36 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window_hook(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;

	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}

void	player_input_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x, vars->player_y - 1);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x - 1, vars->player_y);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x, vars->player_y + 1);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(vars, vars->player_x + 1, vars->player_y);
}