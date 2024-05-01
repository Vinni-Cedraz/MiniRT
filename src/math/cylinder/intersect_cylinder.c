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

static double	cyl_discriminant( const t_ray *ray,	t_bhaskara *bask);

t_intersections	intersect_cylinder(const t_shape *obj, const t_ray *trans_r)
{
	t_intersections	result;
	t_bhaskara		bask;
	double			d;

	d = cyl_discriminant( trans_r, &bask);
	if (d < 0)
		return ((t_intersections){0});
	result.head = ft_lstnew((-bask.b - sqrt(d)) / (2 * bask.a), obj);
	result.head->next = ft_lstnew((-bask.b + sqrt(d)) / (2 * bask.a), obj);
	result.count = 2;
	return (result);
}

static double	cyl_discriminant( const t_ray *ray,	t_bhaskara *bask)
{
	bask->a = pow(ray->direction.x, 2) + pow(ray->direction.z, 2);;
	if (doubles_eq(bask->a, 0))
		return (-1);
	bask->b = (2 * ray->origin.x * ray->direction.x) + \
		(2 * ray->origin.z * ray->direction.z);
	bask->c = (pow(ray->origin.x, 2) + pow(ray->origin.z,2)) - 1;
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}