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

#include "../tests/tester.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		number_of_tokens;
	t_token	*tokens;
	t_world	world;

	fd = 0;
	number_of_tokens = 0;
	if (argc != 2)
		return (0);
	if (!endwith(argv[1], ".rt"))
		printf("Arquivo nao .rt\n");
	fd = open_file(argv[1]);
	file_validation(fd, &number_of_tokens);
	fd = open_file(argv[1]);
	tokens = tokenizer(fd, number_of_tokens);
	print_tokens(tokens, number_of_tokens);
	world = parse_tokens_into_world(tokens);
	print_world(world);
	free(tokens);
}
