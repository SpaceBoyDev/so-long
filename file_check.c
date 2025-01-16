/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:47:40 by dario             #+#    #+#             */
/*   Updated: 2025/01/16 20:23:31 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_validity(int fd, char *arg, t_map_properties *map)
{
	if (fd == -1)
		error_exit("File could not be opened");
	map->name = strjoin_gnl(NULL, arg);
	check_file_extension(arg);
	check_map(fd, map);
	check_map_properties(map);
}

char	*check_file_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		++i;
	if (arg[i - 1] != 'r' || arg[i - 2] != 'e' || arg[i - 3] != 'b'
		|| arg[i - 4] != '.')
		error_exit("Map file extension must be .ber");
	return (arg);
}
