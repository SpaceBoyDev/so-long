/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:13:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/09 21:23:18 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_map_properties
{
	size_t	spawn;
	size_t	exit;
	size_t	objects;
	size_t	x_size;
	size_t	y_size;
}					t_map_properties;


void	show_error_exit(char *error_message);
void	check_file_validity(int fd, char *arg, t_map_properties *map);
char	*check_file_extension(char *arg);
void	check_map_size(int fd, t_map_properties *map);

#endif