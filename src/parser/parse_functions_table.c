/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:26 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/15 18:21:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parse_table	**get_parser_table(void)
{
	static t_parse_table	*table[10] = {
		&parse_ambient_lightning,
		&parse_camera,
		&parse_light,
		&parse_sphere,
		&parse_plane,
		&parse_cylinder,
		NULL,
	};

	return (table);
}
