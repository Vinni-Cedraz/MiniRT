/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:03:52 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 20:34:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(char *str, t_parsectx *ctx)
{
	if (ft_strncmp(str, PLANE_ID, STR_LEN) != 0)
		return;
	printf("plane\n");
	(void)ctx;
	(void)str;
}
