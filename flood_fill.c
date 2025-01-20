/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:31:00 by dario             #+#    #+#             */
/*   Updated: 2025/01/20 05:16:05 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_flood_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1' ||
		map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		data->exit = true;
		return ;
	}
	if (map[y][x] == 'C')
		data->objects_count++;
	map[y][x] = 'F';
	flood_fill(map, data, x + 1, y);
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x, y + 1);
	flood_fill(map, data, x, y - 1);
}
