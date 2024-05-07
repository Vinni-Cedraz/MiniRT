/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:47:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/14 14:34:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static _Bool	is_unique_type_identifier(char *line);
static int		is_non_unique_type(const char *line);
static void		check_counter(t_checker *c);

void	check_type_identifiers(t_checker *c)
{
	const char	identifier[4] = {c->line[0], c->line[1], c->line[2]};

	check_unique_type_identifiers(c);
	if (is_unique_type_identifier(c->line))
		return ;
	if (false == is_non_unique_type(identifier))
	{
		printf(RED"Error, unknown identifier: '%s'\n" RESET, identifier);
		free_and_exit_error(c->line, c->splitted, c->fd);
	}
}

void	check_unique_type_identifiers(t_checker *c)
{
	static const char	identifiers[] = {'A', 'C', 'L'};
	int					idx;

	idx = -1;
	if (false == is_unique_type_identifier(c->line))
		return ;
	while (++idx < 3)
		if (c->line[0] == identifiers[idx])
			c->identifier = idx;
	check_counter(c);
}

_Bool	is_unique_type_identifier(char *line)
{
	const char	unique_types[4][2] = {"A ", "C ", "L "};
	int			idx;

	idx = -1;
	while (++idx < 3)
		if (!ft_strncmp(line, unique_types[idx], 2))
			return (true);
	return (false);
}

void	check_counter(t_checker *c)
{
	static const char	id[] = {'A', 'C'};

	if (c->identifier != LIGHT && c->counters[c->identifier] == true)
	{
		printf(RED "Error: The file can only have a single '%c' identifier\n"
			RESET, id[c->identifier]);
		free_and_exit_error(c->line, c->splitted, c->fd);
	}
	c->counters[c->identifier]++;
}

int	is_non_unique_type(const char *line)
{
	const char	non_unique_types[3][3] = {"pl ", "sp ", "cy "};
	int			i;

	i = -1;
	while (++i < 3)
		if (!ft_strncmp(line, non_unique_types[i], 3))
			return (true);
	return (false);
}
