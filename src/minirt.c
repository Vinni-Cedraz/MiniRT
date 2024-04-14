/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:43 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/05 10:34:14 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc != 2)
		return (0);
	if (!endwith(argv[1], ".rt"))
		printf("Arquivo nao .rt\n");
	fd = open_file(argv[1]);
	file_validation(fd);
}
