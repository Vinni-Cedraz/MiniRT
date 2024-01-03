/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:32 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(char *str, t_parsectx *ctx)
{
	if (ft_strncmp(str, CYLINDER_ID, STR_LEN) != 0)
		return;
	printf("cylinder\n");
	(void)ctx;
	(void)str;
}
