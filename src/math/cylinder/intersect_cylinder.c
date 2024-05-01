/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:33:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 04:34:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	cyl_discriminant(const t_ray r, t_bhaskara *bha);
static _Bool	intersection_within_limits(double t, t_ray r, const t_shape *o);

t_intersections	intersect_cylinder(const t_shape *obj, const t_ray *trans_r,
		const t_tuple dist)
{
	t_intersections	result;
	t_bhaskara		bha;
	double			discr;
	double			t0;
	double			t1;

	(void)dist;
	result = (t_intersections){0};
	discr = cyl_discriminant(*trans_r, &bha);
	if (doubles_eq(bha.a, 0) || discr < 0)
		return (result);
	t0 = (-bha.b - sqrt(discr)) / (2 * bha.a);
	if (intersection_within_limits(t0, *trans_r, obj))
	{
		ft_lstadd_back(&result.head, ft_lstnew(t0, obj));
		result.count++;
	}
	t1 = (-bha.b + sqrt(discr)) / (2 * bha.a);
	if (intersection_within_limits(t1, *trans_r, obj))
	{
		ft_lstadd_back(&result.head, ft_lstnew(t1, obj));
		result.count++;
	}
	return (result);
}

static _Bool	intersection_within_limits(double t, t_ray r,
		const t_shape *cyl)
{
	const double	y = r.origin.y + t * r.direction.y;

	if (y < cyl->max && y > cyl->min)
		return (true);
	return (false);
}

static double	cyl_discriminant(const t_ray r, t_bhaskara *bha)
{
	bha->a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (doubles_eq(bha->a, 0))
		return (-1);
	bha->b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	bha->c = (pow(r.origin.x, 2) + pow(r.origin.z, 2)) - 1;
	return (pow(bha->b, 2) - 4 * bha->a * bha->c);
}
