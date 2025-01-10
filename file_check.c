/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:47:40 by dario             #+#    #+#             */
/*   Updated: 2025/01/10 18:50:55 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_error_exit(char *error_message)
{
	ft_printf("ERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n", error_message);
	exit(0);
}

void	check_file_validity(int fd, char *arg, t_map_properties *map)
{
	if (fd == -1)
		show_error_exit("File could not be opened");
	check_file_extension(arg);
	check_map_size(fd, map);
}

char	*check_file_extension(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
		++i;
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
		show_error_exit("Map file extension must be .ber");
	return (arg);
}

void	check_map_size(int fd, t_map_properties *map)
{
	char *line;
	size_t	i;

	line = get_next_line(fd);
	map->x_size = ft_strlen(line) - 1;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if(line[i] == 'P')
				map->spawn++;
			else if(line[i] == 'E')
				map->exit++;
			else if(line[i] == 'C')
				map->objects++;
			else if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
				show_error_exit("Unrecognized character in map");
			++i;
		}
		if (i - 1 != map->x_size)
			show_error_exit("Map size incorrect");
		ft_printf("%s", line);
		line = get_next_line(fd);
	}
	
	//ft_printf("%s", get_next_line(fd));
}
