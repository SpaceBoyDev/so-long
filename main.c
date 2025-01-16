/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:14:02 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/16 21:28:32 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int					fd;
	t_map_properties	map_properties;

	init_map_properties(&map_properties);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file_validity(fd, argv[1], &map_properties);
		copy_map(&map_properties, fd);
		ft_printf("\nHeight -> %i\n", map_properties.height);
		ft_printf("Width  -> %i\n", map_properties.width);
		ft_printf("Player Pos -> %i,%i\n", map_properties.player_x, map_properties.player_y);
		check_walls(&map_properties);
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
				map->player_x = j;
				map->player_y = i;
			}
			ft_printf("%c", map->tiles[i][j]);
			++j;
		}
		free(line);
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
