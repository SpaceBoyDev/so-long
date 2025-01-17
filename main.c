/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:02 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/17 16:13:45 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_tiles(char **tiles)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tiles[i])
	{
		j = 0;
		while (tiles[i][j])
		{
			ft_printf("%c", tiles[i][j]);
			++j;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int					fd;
	t_map_properties	map;
	t_flood_fill_data	flood_data;
	char				**map_copy;

	init_struct_properties(&map, &flood_data);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file_validity(fd, argv[1], &map);
		save_map(&map, fd);
		check_walls(&map);
		map_copy = copy_map(map.tiles);
		flood_fill(map_copy, &flood_data, map.spawn_x, map.spawn_x);
		read_tiles(map_copy);
		if (flood_data.objects_count != map.num_objects || !flood_data.exit)
			error_exit("This map is not possible to complete");
	}
	else
		error_exit("No argument introduced");
	return (0);
}

void	init_struct_properties(t_map_properties *map, t_flood_fill_data *data)
{
	map->num_spawns = 0;
	map->num_exits = 0;
	map->num_objects = 0;
	map->width = 0;
	map->height = 0;
	data->exit = false;
	data->objects_count = 0;
}


