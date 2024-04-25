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

#include "minirt_bonus.h"

static void	check_error(int error, const t_token *tokens);
static void	init_world(int number_of_tokens, t_world *world);
static void	load_world(int number_of_tokens, t_world *world, t_token *tokens);

t_world	parse_tokens_into_world(t_token *tokens, int number_of_tokens)
{
	t_world			world;

	world = (t_world){0};
	init_world(number_of_tokens, &world);
	load_world(number_of_tokens, &world, tokens);
	printf(GREEN"Parsing Done\n"RESET);
	return (world);
}

static void	init_world(int number_of_tokens, t_world *world)
{
	const int	number_of_non_shape_tokens = world->lights_idx + 3;

	world->fixed_count = (number_of_tokens - number_of_non_shape_tokens);
	world->shapes = ft_calloc(sizeof(t_shape), world->fixed_count);
	world->moving_idx = world->fixed_count - 1;
}

static void	load_world(int number_of_tokens, t_world *world, t_token *tokens)
{
	int				error;
	const t_token	*free_tokens = tokens;

	while (number_of_tokens--)
	{
		error = parse_functions()[tokens->type](*tokens, world);
		check_error(error, free_tokens);
		tokens++;
	}
}

static void	check_error(int error, const t_token *tokens)
{
	if (error == ERROR)
	{
		free((void *)tokens);
		exit(EXIT_FAILURE);
	}
}
