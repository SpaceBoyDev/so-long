/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:02 by darmarti          #+#    #+#             */
/*   Updated: 2025/02/18 18:59:48 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_structs(t_vars *vars, t_map *map, t_flood_data *data)
{
	vars->map = map;
	vars->flood_data = data;
	vars->player_img = NULL;
	map->num_spawns = 0;
	map->num_exits = 0;
	map->num_objs = 0;
	map->width = 0;
	map->height = 0;
	map->tiles = NULL;
	data->exit = false;
	data->objects_count = 0;
}

int	main(int argc, char **argv)
{
	int				fd;
	t_vars			vars;
	t_map			map;
	t_flood_data	flood_data;
	char			**map_copy;

	init_structs(&vars, &map, &flood_data);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file_validity(fd, argv[1], &map);
		if (!save_map(&map, argv[1], fd))
			error_exit_free("Error saving the map", &map);
		check_walls(&map);
		map_copy = copy_map(map.tiles, map.height);
		flood_fill(map_copy, &flood_data, map.spawn_x, map.spawn_y);
		free_map(map_copy);
		if (flood_data.objects_count != map.num_objs || !flood_data.exit)
			error_exit_free("This map is not possible to complete", &map);
		start_game(&vars);
		free_vars(&vars);
	}
	else
		error_exit("No argument introduced");
	return (0);
}
