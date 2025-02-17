/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darmarti <darmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:20:31 by dario             #+#    #+#             */
/*   Updated: 2025/02/17 19:41:54 by darmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_addr(char *string)
{
	int i = 0;
	while (string[i])
	{
		ft_printf("\nDirección de %c es %p\n", string[i], &string[i]);
		++i;
	}
}

void	check_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->tiles[0][i] && i < map->width)
	{
		if (map->tiles[0][i] != '1')
			error_exit_free("Upper wall incomplete", map);
		++i;
	}
	i = 0;
	while (map->tiles[i] && i < map->height)
	{
		if (map->tiles[i][0] != '1' || map->tiles[i][map->width - 1] != '1')
			error_exit_free("There must be a wall surrounding the map", map);
		++i;
	}
	i = 0;
	while (map->tiles[map->height - 1][i] && i < map->width)
	{
		if (map->tiles[map->height - 1][i] != '1')
			error_exit_free("Lower wall incomplete", map);
		++i;
	}
}

char	*check_size(t_map *map, int fd, size_t i, char *line)
{
	if (line)
		free(line);
	if (i != map->width)
		return (error_exit("Map size incorrect"));
	return (get_next_line(fd));
}

void	check_map_properties(t_map *map)
{
	if (map->num_spawns != 1)
		error_exit_free("There must be only one spawn point", map);
	else if (map->num_exits != 1)
		error_exit_free("There must be only one exit", map);
	else if (map->num_objs < 1)
		error_exit_free("There must be at least one object", map);
}

void	check_char(char *line, t_map *map, int fd)
{
	size_t	i;

	while (line)
	{
		i = 0;
		map->height++;
		while (line[i])
		{
			if (line[i] == '\n')
				break ;
			if (line[i] == 'P')
				map->num_spawns++;
			else if (line[i] == 'E')
				map->num_exits++;
			else if (line[i] == 'C')
				map->num_objs++;
			else if (line[i] != '0' && line[i] != '1')
			{
				while (line)
				{
					free(line);
					line = get_next_line(fd);
				}
				free(line);
				line = NULL;
				error_exit("Unrecognized character");
			}
			++i;
		}
		free(line);
		line = NULL;
		line = check_size(map, fd, i, line);
	}
}

void	check_map(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_exit("The map is empty");
	map->width = ft_strlen(line) - 1;
	check_char(line, map, fd);
	free(line);
}
