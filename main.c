/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:02 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/16 19:45:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map_properties map_properties;
	init_map_properties(&map_properties);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file_validity(fd, argv[1], &map_properties);
		copy_map(&map_properties, fd);
		ft_printf("\nHeight -> %i\n", map_properties.height);
		ft_printf("Width  -> %i\n", map_properties.width);
		check_walls(&map_properties);
		//start_game(&map_properties);
	}
	else
		error_exit("No argument introduced.");

	return (0);
}

void	init_map_properties(t_map_properties *map_properties)
{
	map_properties->num_spawns = 0;
	map_properties->num_exits = 0;
	map_properties->num_objects = 0;
	map_properties->width = 0;
	map_properties->height = 0;
}

void	fill_map(int fd, t_map_properties *map)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			map->tiles[i][j] = line [j];
			ft_printf("%c", map->tiles[i][j]);
			++j;
		}
		//free(line);
		line = get_next_line(fd);
		++i;
	}
}


char	**copy_map(t_map_properties *map, int fd)
{
	size_t	i;

	i = 0;
	map->tiles = (char **)ft_calloc(sizeof(char *), map->height + 1);
	if (!map->tiles)
		return (NULL);
	while (i < map->height)
	{
		map->tiles[i] = (char *)ft_calloc(sizeof(char), map->width + 1);
		if (!map->tiles[i])
			return (NULL);
		++i;
	}
	map->tiles[map->height + 1] = ft_calloc(sizeof(char), map->width + 1);
	close(fd);
	fd = open(map->name, O_RDONLY);
	fill_map(fd, map);
	return (map->tiles);
}

// -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }


// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}

// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

