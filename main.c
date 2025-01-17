/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:02 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/17 16:51:02 by dario            ###   ########.fr       */
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

	flood_data.exit = false;
	flood_data.objects_count = 0;

	init_map_properties(&map);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file_validity(fd, argv[1], &map);
		save_map(&map, fd);
		ft_printf("\nHeight -> %i\n", map.height);
		ft_printf("Width  -> %i\n", map.width);
		ft_printf("Player Pos -> %i,%i\n", map.spawn_x, map.spawn_y);
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

void	init_map_properties(t_map_properties *map_properties)
{
	map_properties->num_spawns = 0;
	map_properties->num_exits = 0;
	map_properties->num_objects = 0;
	map_properties->width = 0;
	map_properties->height = 0;
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		rows;

	rows = ft_strlen(*map);
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
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
			if (map->tiles[i][j] == 'P')
			{
				map->spawn_x = j;
				map->spawn_y = i;
			}
			ft_printf("%c", map->tiles[i][j]);
			++j;
		}
		free(line);
		line = get_next_line(fd);
		++i;
	}
}

char	**save_map(t_map_properties *map, int fd)
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
