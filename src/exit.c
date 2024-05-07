/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:24:15 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 13:24:20 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void    ft_key(mlx_key_data_t button, void *p)
{
	mlx_t *mlx;

	mlx = (mlx_t *)p;
	printf("%i", button.key);
	if (button.key == 32)
	{
		mlx_close_window(mlx);
	}
}

void exit_free(t_world	*world)
{
	free(world->tokens);
	free(world->shapes);
}