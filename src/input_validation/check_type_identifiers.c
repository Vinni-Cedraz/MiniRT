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

#include "minirt.h"

static _Bool	is_unique_type_identifier(char *line);
static int		is_non_unique_type(const char *line);
static void		check_counter(t_checker checker);

void	check_unique_type_identifiers(char *line, t_split *splitted, int fd)
{
	static int	counter_ambient;
	static int	counter_camera;
	static int	counter_light;

	if (is_unique_type_identifier(line) == false)
		return ;
	if (line[0] == 'A')
		check_counter((t_checker){'A', splitted, &counter_ambient, line, fd});
	if (line[0] == 'C')
		check_counter((t_checker){'C', splitted, &counter_camera, line, fd});
	if (line[0] == 'L')
		check_counter((t_checker){'L', splitted, &counter_light, line, fd});
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

void	check_counter(t_checker checker)
{
	if ((*checker.counter) > 0)
	{
		printf(RED "Error: The file can only have a single '%c' identifier\n"
			RESET, checker.identifier);
		free_and_exit_error(checker.line, checker.splitted, checker.fd);
	}
	(*checker.counter)++;
}

void	check_type_identifiers(char *line, t_split *splitted, int fd)
{
	const char	identifier[4] = {line[0], line[1], line[2]};

	if (is_unique_type_identifier(line))
		return ;
	if (false == is_non_unique_type(identifier))
	{
		printf(RED"Error, unknown identifier: '%s'\n" RESET, identifier);
		free_and_exit_error(line, splitted, fd);
	}
}

int	is_non_unique_type(const char *line)
{
	const char	non_unique_types[4][3] = {"pl ", "sp ", "cy ", "\n"};
	int			i;

	i = -1;
	while (++i < 4)
		if (!ft_strncmp(line, non_unique_types[i], 3))
			return (true);
	return (false);
}
