/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/13 17:42:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_unique_type_identifiers(char *line, t_split *splitted);
void	check_type_identifiers(char *line, t_split *splitted);
void	print_error_and_free(char *line, t_split *splitted);
void	is_valid_type(char *line, t_split *splitted);

_Bool	file_validation(int fd)
{
	char	*line;
	t_split	*splitted;
	size_t	idx;

	idx = 1;
	line = ft_gnl(fd);
	while (line)
	{
		splitted = ft_split(line, ' ');
		check_unique_type_identifiers(line, splitted);
		check_type_identifiers(line, splitted);
		while (idx < splitted->count)
		{
		}
		line = ft_gnl(fd);
	}
	return (true);
}

// unique type can only be declared once each in the whole file, static
// variables keep track of this
void	check_unique_type_identifiers(char *line, t_split *splitted)
{
	static int	counter_ambient;
	static int	counter_camera;
	static int	counter_light;

	is_valid_type(line, splitted);
	if (line[0] == 'A')
	{
		if (counter_ambient > 0)
			print_error_and_free(line, splitted);
		counter_ambient++;
	}
	if (line[0] == 'C')
	{
		if (counter_camera > 0)
			print_error_and_free(line, splitted);
		counter_camera++;
	}
	if (line[0] == 'L')
	{
		if (counter_light > 0)
			print_error_and_free(line, splitted);
		counter_light++;
	}
}

void	is_valid_type(char *line, t_split *splitted)
{
	const char	unique_types[3] = {"ACL"};

	if (!ft_strchr(unique_types, line[0]))
		print_error_and_free(line, splitted);
}

void	check_type_identifiers(char *line, t_split *splitted)
{
	const char	non_unique[2] = {line[0], line[1]};
	const char	non_unique_types[4][2] = {"pl", "sp", "cy", "\n"};
	int			idx;

	idx = 0;
	while (idx < 4)
	{
		if (!ft_strncmp(non_unique, non_unique_types[idx], 2))
			print_error_and_free(line, splitted);
		idx++;
	}
}

void	print_error_and_free(char *line, t_split *splitted)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Invalid type identifier: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\n", 2);
	ft_free_t_split(splitted);
	exit(1);
}
