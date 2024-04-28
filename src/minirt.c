/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:43 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/14 18:48:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		number_of_tokens;
	t_token	*tokens;
	t_world	world;
	mlx_t	*mlx;

	fd = 0;
	number_of_tokens = 0;
	mlx = mlx_init(SIZEW, SIZEH, "TRinim", true);
	if (argc != 2)
		return (0);
	if (!endwith(argv[1], ".rt"))
		printf("Arquivo nao .rt\n");
	fd = open_file(argv[1]);
	file_validation(fd, &number_of_tokens);
	fd = open_file(argv[1]);
	world.image = create_image(mlx);
	tokens = tokenizer(fd, number_of_tokens);
	world = parse_tokens_into_world(tokens, number_of_tokens);
	render(world.image, world);
	mlx_image_to_window(mlx, world.image, 0, 0);
	mlx_loop(mlx);
	free(tokens);
	free(world.shapes);
}
