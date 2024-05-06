/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:08:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/14 18:03:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static _Bool	has_forbidden_chars(const char *string);
static _Bool	has_consecutive_separators(const char *string);
static _Bool	is_separator(char ch);

void	validate_line(char *line, t_split *splitted, int fd)
{
	const char	**strings = (const char **)splitted->words;
	const int	len = splitted->count;
	int			idx;

	idx = 1;
	while (idx < len)
	{
		if (has_forbidden_chars(strings[idx])
			|| has_consecutive_separators(strings[idx]))
		{
			printf(RED "Error: invalid input: %s" RESET, strings[idx]);
			free_and_exit_error(line, splitted, fd);
		}
		idx++;
	}
}

static _Bool	has_forbidden_chars(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (true);
	i++;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && !is_separator(str[i]) && str[i] != '-')
			return (true);
		i++;
	}
	return (false);
}

static _Bool	has_consecutive_separators(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
	{
		if (is_separator(string[i + 1]) && is_separator(string[i]))
			return (true);
		i++;
	}
	return (false);
}

static _Bool	is_separator(char ch)
{
	return (ch == ',' || ch == '.');
}
