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

#include "../include/minirt.h"

static void	print_tokens(t_token *tokens, int nb);

int	main(int argc, char **argv)
{
	int		fd;
	int		number_of_tokens;
	t_token	*tokens;

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
	free(tokens);
}

void	print_tokens(t_token *tokens, int nb)
{
	int			i;
	int			j;
	const char	identifiers[6][9] = {\
			"AMBIENT", "CAMERA", "LIGHT", "SPHERE", "PLANE", "CYLINDER"};

	i = 0;
	while (i < nb)
	{
		printf("Token %d:\n", i + 1);
		printf("  Type: %s\n", identifiers[tokens[i].type]);
		j = 0;
		while (&tokens[i] && j < 5 && tokens[i].args[j][0] != '\0')
		{
			printf("  Arg %d: %s\n", j + 1, tokens[i].args[j]);
			j++;
		}
		i++;
	}
}
