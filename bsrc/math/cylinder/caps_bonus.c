/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:41:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/09 16:48:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

_Bool	check_cap(const t_ray ray, const double t);

void	intersect_caps(const t_shape *cyl, const t_ray r, t_intersections *xs)
{
	const double	t0 = (cyl->min - r.origin.y) / r.direction.y;
	const double	t1 = (cyl->max - r.origin.y) / r.direction.y;

	if (FALSE == cyl->closed || doubles_eq(r.direction.y, 0))
		return ;
	if (check_cap(r, t0))
	{
		ft_lstadd_back(&xs->head, ft_lstnew(t0, cyl));
		xs->count++;
	}
	if (check_cap(r, t1))
	{
		ft_lstadd_back(&xs->head, ft_lstnew(t1, cyl));
		xs->count++;
	}
}

_Bool	check_cap(const t_ray ray, const double t)
{
	const double	x = ray.origin.x + t * ray.direction.x;
	const double	z = ray.origin.z + t * ray.direction.z;
	const _Bool		within_radius = ((pow(x, 2) + pow(z, 2)) <= 1);

	return (within_radius);
}
