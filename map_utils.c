/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:11:43 by dario             #+#    #+#             */
/*   Updated: 2025/02/18 19:07:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**save_map(t_map *map, char *name, int fd)
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
	close(fd);
	fd = open(name, O_RDONLY);
	fill_map(fd, map);
	close(fd);
	return (map->tiles);
}

void	fill_map(int fd, t_map *map)
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
		while (line[j] && j < map->width)
		{
			map->tiles[i][j] = line [j];
			if (map->tiles[i][j] == 'P')
			{
				map->spawn_x = j;
				map->spawn_y = i;
			}
			++j;
		}
		free(line);
		line = get_next_line(fd);
		++i;
	}
}

char	**copy_map(char **map, int rows)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(rows + 1, sizeof(char *));
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
