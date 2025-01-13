/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:07:27 by dario             #+#    #+#             */
/*   Updated: 2025/01/12 19:36:20 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_message)
{
	ft_printf("ERROR\n-----\n");
	if (error_message)
		ft_printf("%s\n", error_message);
	exit(0);
}