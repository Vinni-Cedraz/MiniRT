/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:24:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/14 14:00:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

_Bool	file_validation(int fd)
{
	char	*line;
	t_split	*splitted;

	line = ft_gnl(fd);
	while (line)
	{
		splitted = ft_split(line, ' ');
		check_unique_type_identifiers(line, splitted, fd);
		check_type_identifiers(line, splitted, fd);
		ft_putstr(line);
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
