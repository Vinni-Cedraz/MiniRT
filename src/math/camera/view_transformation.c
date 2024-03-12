/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:24:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/08 11:06:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static t_matrix	orientation_matrix(t_tuple lft, t_tuple up, t_tuple frwd);
// static t_matrix	move_scene_into_place(t_matrix *orientation, t_tuple from);

t_matrix	view_transform(t_tuple from, t_tuple forward, t_tuple up)
{
	(void)from;
	(void)forward;
	(void)up;
	return (t_matrix){0};
}

// static t_matrix	orientation_matrix(t_tuple left, t_tuple truup, t_tuple forward)
// {
// 	(void)left;
// 	(void)truup;
// 	(void)forward;
// 	return (t_matrix){0};
// }
//
// static t_matrix	move_scene_into_place(t_matrix *orientation, t_tuple from)
// {
// 	(void)orientation;
// 	(void)from;
// 	return (t_matrix){0};
// }
