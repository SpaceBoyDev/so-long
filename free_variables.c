/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:46:45 by dario             #+#    #+#             */
/*   Updated: 2025/01/30 19:30:26 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_vars(t_vars *vars)
{
	// mlx_terminate(vars->mlx);
	// free(vars->mlx);
	free_map_struct(vars->map);
	//free(vars->map_properties);
	return (NULL);
}

char	*free_map_struct(t_map *map)
{
	int	i;

	if (!map->tiles)
		return (NULL);
	i = 0;
	while (map->tiles[i])
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
	return (NULL);
}

char	*free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
