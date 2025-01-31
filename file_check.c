/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:47:40 by dario             #+#    #+#             */
/*   Updated: 2025/01/31 09:52:06 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_validity(int fd, char *arg, t_map *map)
{
	if (fd == -1)
		error_exit("File could not be opened");
	if (!check_file_extension(arg))
		error_exit("Map file extension must be .ber");
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
		return (NULL);
	return (arg);
}
