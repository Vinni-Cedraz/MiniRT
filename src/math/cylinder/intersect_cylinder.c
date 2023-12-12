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

static float			cyl_discriminant(t_ray ray, t_baskara *bask);
static float			_y0(t_ray *r, t_baskara *b);
static float			_y1(t_ray *r, t_baskara *b);
static t_intersection	create_cylinder_intersections(void **o, t_baskara *bask,
							t_ray *r, const t_cylinder *cyl);

t_intersection	intersect_cylinder(void **obj, t_tuple obj_dist_to_ray, t_ray r)
{
	t_intersection			xs;
	float					dis;
	t_baskara				bask;
	const t_cylinder		*cyl = (t_cylinder *)*obj;

	(void)obj_dist_to_ray;
	ft_bzero((void *)&xs, sizeof(t_intersection));
	bask.a = (pow(r.direction[X], 2) + pow(r.direction[Z], 2));
	if (floats_eq(0, bask.a))
	{
		intersect_caps(cyl, r, xs.head);
		return (xs);
	}
	dis = cyl_discriminant(r, &bask);
	if (dis < 0)
		return (xs);
	xs = create_cylinder_intersections(obj, &bask, &r, cyl);
	intersect_caps(cyl, r, xs.head);
	return (xs);
}

static t_intersection	create_cylinder_intersections(void **o, t_baskara \
	*bask, t_ray *r, const t_cylinder *cyl)
{
	t_node	*arr[3];
	int		counter;

	counter = 0;
	ft_bzero((void *)arr, sizeof(t_node *) * 3);
	if (_y0(r, bask) > cyl->min && _y0(r, bask) < cyl->max)
		arr[counter++] = intersection(bask->t0, o);
	if (_y1(r, bask) > cyl->min && _y1(r, bask) < cyl->max)
		arr[counter++] = intersection(bask->t1, o);
	return (link_intersection_nodes(arr));
}

static float	_y0(t_ray *r, t_baskara *b)
{
	return (r->origin[Y] + b->t0 * r->direction[Y]);
}

static float	_y1(t_ray *r, t_baskara *b)
{
	return (r->origin[Y] + b->t1 * r->direction[Y]);
}

static float	cyl_discriminant(t_ray ray, t_baskara *bask)
{
	float	dis;

	bask->b = 2 * ray.origin[X] * ray.direction[X] + 2 * ray.origin[Z]
		* ray.direction[Z];
	bask->c = pow(ray.origin[X], 2) + pow(ray.origin[Z], 2) - 1;
	dis = pow(bask->b, 2) - 4 * bask->a * bask->c;
	bask->t0 = (-bask->b - sqrt(dis)) / (2 * bask->a);
	bask->t1 = (-bask->b + sqrt(dis)) / (2 * bask->a);
	return (dis);
}
