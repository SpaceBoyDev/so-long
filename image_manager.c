/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:12:28 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/29 19:14:23 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*draw_map(t_vars *vars, char **map)
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
				image_to_window(vars->mlx, tree, j, i, 1);
			else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E'
					|| map[i][j] == 'P')
				image_to_window(vars->mlx, ground, j, i, 1);
			++j;
		}
		++i;
	}
	draw_map_misc(vars, map);
	return (NULL);
}

char	*draw_map_misc(t_vars *vars, char **map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				create_player(vars, j, i);
			else if (map[i][j] == 'C')
				image_to_window(vars->mlx, "./textures/object.png", j, i, 2);
			else if (map[i][j] == 'E')
				image_to_window(vars->mlx, "./textures/hole.png", j, i, 2);
			++j;
		}
		++i;
	}
	return (NULL);
}