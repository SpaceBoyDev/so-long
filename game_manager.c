/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:32:09 by dario             #+#    #+#             */
/*   Updated: 2025/01/23 19:24:31 by dario            ###   ########.fr       */
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
	draw_map(vars->mlx, vars->map_properties->tiles);
	// mlx_texture_t	*texture;
	// texture = mlx_load_png("./textures/tree.png");
	// mlx_image_t	*img;
	// img = mlx_texture_to_image(vars->mlx, texture);
	// mlx_resize_image(img, 16 * SCALE, 16 * SCALE);
	// mlx_image_to_window(vars->mlx, img, 0, 0);
	mlx_loop(vars->mlx);
}

mlx_image_t	*image_to_window(mlx_t *mlx, char *file, int x, int y, int depth)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				scale_multi;

	scale_multi = 16 * SCALE;
	texture = mlx_load_png(file);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img || !mlx_resize_image(img, scale_multi, scale_multi))
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_image_to_window(mlx, img, x * scale_multi, y * scale_multi);
	mlx_set_instance_depth(&img->instances[0], depth);
	mlx_delete_texture(texture);
	return (img);
}

char	*draw_map(mlx_t *mlx, char **map)
{
	size_t	i;
	size_t	j;
	char	*tree;
	char	*ground;
	
	tree = "./textures/tree.png";
	ground = "./textures/ground.png";

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				image_to_window(mlx, tree, j, i, 1);
			else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E'
					|| map[i][j] == 'P')
				image_to_window(mlx, ground, j, i, 1);
			++j;
		}
		++i;
	}
	return (NULL);
}
