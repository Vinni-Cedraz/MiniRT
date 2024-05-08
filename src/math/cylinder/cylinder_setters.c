/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_setters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:05:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/26 15:07:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_cyl_min_max(t_shape *cyl, double min, double max, _Bool closed)
{
	cyl->min = min;
	cyl->max = max;
	cyl->closed = closed;
}
