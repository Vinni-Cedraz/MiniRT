/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:26:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/30 09:43:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	combine_surface_and_light(t_lighting *o, t_tuple c, t_tuple l);
static void	set_colors_to_black(t_tuple colr1, t_tuple colr2);
static void	set_reflect_v(t_colors *c, t_lighting *obj);
static void	point_in_shadow(t_tuple ambient, t_tuple res);

void	calculate_lighting(t_lighting *obj, t_tuple result)
{
}

static inline void	point_in_shadow(t_tuple ambient, t_tuple res)
{
}

static inline void	combine_surface_and_light(t_lighting *obj,
		t_tuple true_colr, t_tuple lightv)
{
}

static inline void	set_colors_to_black(t_tuple colr1, t_tuple colr2)
{
}

static void	set_reflect_v(t_colors *c, t_lighting *obj)
{
}
