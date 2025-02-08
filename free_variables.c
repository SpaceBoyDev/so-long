/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:46:45 by dario             #+#    #+#             */
/*   Updated: 2025/02/08 20:17:16 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_vars(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->player_img);
	free_map_struct(vars->map);
	return (NULL);
}

char	*free_map_struct(t_map *map)
{
	free_map(map->tiles);
	map->tiles = NULL;
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
	map = NULL;
	return (NULL);
}
