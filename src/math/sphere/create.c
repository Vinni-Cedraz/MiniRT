/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/16 16:29:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	create_sphere(void)
{
	static int	id;
	t_sphere	sphere;

	sphere.radius = 1;
	sphere.origin = create_point(0, 0, 0);
	sphere.id = id++;
	return (sphere);
}
