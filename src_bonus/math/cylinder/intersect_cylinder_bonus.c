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

#include "minirt_bonus.h"

static double	cyl_discriminant(const t_ray r, t_bhaskara *bask);
static _Bool	intersection_within_limits(double t, t_ray r, const t_shape *o);
static void		set_t(const t_shape *obj, const t_ray *trans_r, \
					t_bhaskara *bask, t_intersections *result);

t_intersections	intersect_cylinder(const t_shape *obj, const t_ray *trans_r,
									  const t_tuple dist)
{
	t_intersections	result;
	t_bhaskara		bask;

	(void)dist;
	result = (t_intersections){0};
	bask.a = pow(trans_r->direction.x, 2) + pow(trans_r->direction.z, 2);
	if (doubles_eq(bask.a, 0))
	{
		intersect_caps(obj, *trans_r, &result);
		return (result);
	}
	set_t(obj, trans_r, &bask, &result);
	intersect_caps(obj, *trans_r, &result);
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

static double	cyl_discriminant(const t_ray r, t_bhaskara *bask)
{
	if (doubles_eq(bask->a, 0))
		return (-1);
	bask->b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	bask->c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - 1;
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}

static void	set_t(const t_shape *obj, const t_ray *trans_r, t_bhaskara *bask,
					 t_intersections *result)
{
	double			discr;
	double			t0;
	double			t1;

	discr = cyl_discriminant(*trans_r, bask);
	if (discr < 0)
		return ;
	t0 = (-bask->b - sqrt(discr)) / (2 * bask->a);
	if (intersection_within_limits(t0, *trans_r, obj))
	{
		ft_lstadd_back(&result->head, ft_lstnew(t0, obj));
		result->count++;
	}
	t1 = (-bask->b + sqrt(discr)) / (2 * bask->a);
	if (intersection_within_limits(t1, *trans_r, obj))
	{
		ft_lstadd_back(&result->head, ft_lstnew(t1, obj));
		result->count++;
	}
}
