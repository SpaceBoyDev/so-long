/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:07:27 by dario             #+#    #+#             */
/*   Updated: 2025/01/20 21:33:46 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*error_exit(char *error_message)
{
	ft_printf("ERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n", error_message);
	exit(0);
}

void	error_only(char *error_message)
{
	ft_printf("ERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n", error_message);
}

char	*error_exit_free(char *error_message, t_map *map)
{
	free_map(map->tiles);
	ft_printf("ERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n", error_message);
	exit(0);
}
