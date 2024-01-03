/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:11 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light(char *str, t_parsectx *ctx)
{
	if (ft_strncmp(str, LIGHT_ID, STR_LEN) != 0)
		return;
	printf("light\n");
	(void)ctx;
	(void)str;
}
