/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_into_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:24:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_error(int error, const t_token *tokens);

t_world	parse_tokens_into_world(t_token *tokens, int number_of_tokens)
{
	const t_token	*free_tokens = tokens;
	static t_world	world;
	int				error;

	world.objs = ft_calloc(sizeof(t_sphere), number_of_tokens);
	world.count = number_of_tokens - 3;
	printf(GREEN"WORLD COUNT: %d\n"RESET, world.count);
	while (number_of_tokens--)
	{
		error = parse_functions()[tokens->type](*tokens, &world);
		check_error(error, free_tokens);
		tokens++;
	}
	return (world);
}

static void	check_error(int error, const t_token *tokens)
{
	if (error == ERROR)
	{
		free((void *)tokens);
		exit(EXIT_FAILURE);
	}
}
