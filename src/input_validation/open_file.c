/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:16:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/12 16:16:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "minirt.h"

int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf(RED"Arquivo nao encontrado\n"RESET);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
