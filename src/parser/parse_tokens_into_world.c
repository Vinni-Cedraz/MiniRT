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

t_world	parse_tokens_into_world(t_token *tokens)
{
	static t_world	world;

	world.camera = create_camera(SIZEH, SIZEW, M_PI / 3);
	while (tokens->type != END)
	{
		parse_functions()[tokens->type](*tokens, &world);
		tokens++;
	}
	return (world);
}
