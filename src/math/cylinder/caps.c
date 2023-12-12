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

#include "minirt.h"

static void		add_cap_intersection(const float t, const void **p,
					t_node *node);
static t_bool	check_cap(const t_ray ray, const float t);

void	intersect_caps(const t_cylinder *cyl, const t_ray r, t_node *head)
{
	const float	lower_t = (cyl->min - r.origin[Y]) / r.direction[Y];
	const float	upper_t = (cyl->max - r.origin[Y]) / r.direction[Y];
	const void	**obj = (const void **)&cyl;

	if (cyl->closed == FALSE || fabs(r.direction[Y]) < EPSILON)
		return ;
	if (check_cap(r, lower_t))
		add_cap_intersection(lower_t, obj, head);
	if (check_cap(r, upper_t))
		add_cap_intersection(upper_t, obj, head);
}

t_bool	check_cap(const t_ray ray, const float t)
{
	const float		x = ray.origin[X] + t * ray.direction[X];
	const float		z = ray.origin[Z] + t * ray.direction[Z];
	const t_bool	within_radius = (pow(x, 2) + pow(z, 2) <= 1);

	return (within_radius);
}

void	add_cap_intersection(const float t, const void **p, t_node *head)
{
	if (ft_lstsize(head) == 0)
		head = intersection(t, (void **)p);
	else if (ft_lstsize(head) == 1)
		head->next = intersection(t, (void **)p);
}
