/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:20:31 by dario             #+#    #+#             */
/*   Updated: 2025/01/13 18:40:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_size(t_map_properties *map, int fd, size_t i)
{
	if (i != map->width)
		error_exit("Map size incorrect");
	return (get_next_line(fd));
}

void	check_map_properties(t_map_properties *map)
{
	if (map->num_spawns != 1)
		error_exit("There must be only one spawn point");
	else if (map->num_exits != 1)
		error_exit("There must be only one exit");
	else if (map->num_objects < 1)
		error_exit("There must be at least one object");
}

void	check_map(int fd, t_map_properties *map)
{
	char	*line;
	size_t	i;

	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	while (line)
	{
		i = 0;
		map->height++;
		while (line[i])
		{
			if (line[i] == '\n')
				break;
			if (line[i] == 'P')
				map->num_spawns++;
			else if (line[i] == 'E')
				map->num_exits++;
			else if (line[i] == 'C')
				map->num_objects++;
			else if (line[i] != '0' && line[i] != '1')
				error_exit("Unrecognized character in map");
			++i;
		}
		line = check_size(map, fd, i);
	}
}
