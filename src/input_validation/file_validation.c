/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/14 18:47:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

_Bool	file_validation(int fd, int *valid_lines)
{
	char	*line;
	t_split	*splitted;

	line = ft_gnl(fd);
	if (!line)
		free_and_exit_error(line, NULL, fd);
	while (line)
	{
		splitted = ft_split(line, ' ');
		if (line[0] != '\n')
		{
			(*valid_lines)++;
			check_type_identifiers(line, splitted, fd);
			validate_line(line, splitted, fd);
		}
		free(line);
		ft_free_t_split(splitted);
		line = ft_gnl(fd);
	}
	return (true);
}

void	free_and_exit_error(char *line, t_split *splitted, int fd)
{
	while (line)
	{
		free(line);
		line = ft_gnl(fd);
	}
	ft_free_t_split(splitted);
	exit(1);
}
