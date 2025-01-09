/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:13:51 by darmarti          #+#    #+#             */
/*   Updated: 2025/01/09 21:41:46 by dario            ###   ########.fr       */
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
	bool	has_spawn;
	bool	has_end;
	bool	has_object;
	size_t	max_len;
	struct s_list	*next;
}					t_map_properties;


void	show_error_exit(char *error_message);
void	check_file_validity(int fd, char *arg);
char	*check_file_extension(char *arg);
void	check_map_size(int fd);

#endif