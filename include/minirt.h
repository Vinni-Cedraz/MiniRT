/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/23 19:59:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft_gnl/libft.h"
# include <math.h>

# define EPSILON 1e-6
# define X 0
# define Y 1
# define Z 2
# define W 3
# define VECTOR 0
# define POINT 1
# define FALSE 0
# define TRUE 1

typedef float			t_tuple[4];
typedef unsigned short	t_bool;

void	create_point(t_tuple tuple);
void	create_vector(t_tuple tuple);
t_bool	compare_floats(float a, float b);
void	add_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void	subtract_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void	negate_tuple(const t_tuple a, t_tuple result);
void	multiply_tuple_by_scalar(const t_tuple a, const float s, t_tuple res);
t_bool	compare_floats(float a, float b);
float	magnitude(const t_tuple vec);
short	normalize(const t_tuple vec, t_tuple result);
short	dot(const t_tuple a, const t_tuple b, float dot_product);
short	cross(const t_tuple a, const t_tuple b, t_tuple cross_product);

#endif
