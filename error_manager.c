/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:07:27 by dario             #+#    #+#             */
/*   Updated: 2025/02/18 18:58:57 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_msg(char *error_message)
{
	ft_printf(RED"\n-----\nERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n"RST, error_message);
}

char	*error_exit(char *error_message)
{
	error_msg(error_message);
	exit(0);
}

void	error_only(char *error_message)
{
	error_msg(error_message);
}

char	*error_exit_free(char *error_message, t_map *map)
{
	free_map(map->tiles);
	error_msg(error_message);
	exit(0);
}
