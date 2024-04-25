/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:32 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_cylinder(t_token token, t_world *w)
{
	(void)w;
	printf("%s\n", types[token.type]);
	exit(0);
	return (0);
}
