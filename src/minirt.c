/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:43 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/05 10:34:14 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(sizew, sizeh, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// if (argc != 2)
	// 	return (0);
	// if (!endwith(argv[1], ".rt"))
	// 	printf("Arquivo nao .rt\n");
	(void)argc;
	(void)argv;
	render_a_default_world(mlx);
	mlx_loop(mlx);
}
