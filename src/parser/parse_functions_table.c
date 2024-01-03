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

const t_idtable *get_parser_table(void)
{
	const static t_idtable table[TOTAL_OBJS] = {
		{"A", parse_ambient_lightning},
		{"C", parse_camera},
		{"L", parse_light},
		{"pl", parse_plane},
		{"sp", parse_sphere},
		{"cy", parse_cylinder}
	};

	return (table);
}
