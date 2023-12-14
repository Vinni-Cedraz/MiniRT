/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funtions_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:26 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/05 11:10:06 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parse_table	**get_parser_table(void)
{
	static t_parse_table	*table[10] = {
		&parse_light,
		&parse_plane,
		&parse_sphere,
		&parse_cylinder,
		&parse_ambient_lightning,
		&parse_camera,
		NULL,
	};

	return (table);
}
