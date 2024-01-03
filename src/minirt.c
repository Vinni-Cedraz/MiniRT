/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:43 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 19:28:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	mlx_t* mlx;
	t_world *world;

	mlx = mlx_init(SIZEW, SIZEH, "MLX42", true);
	if (!mlx)
		return (0);
	if (argc != 2)
		return (0);
	if (!endwith(argv[1], ".rt"))
		printf("Arquivo nao .rt\n");
	world = parse_file(argv[1]);
	if (world == NULL)
		return (0);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
}
