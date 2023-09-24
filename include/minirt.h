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

# define EPSILON 0.0001
# define X 0
# define Y 1
# define Z 2
# define W 3
# define VECTOR 0
# define POINT 1
# define FALSE 0
# define TRUE 1

typedef float	t_tuple[4];
typedef char t_bool;

void	add_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void	subtract_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void	negate_tuple(const t_tuple a, t_tuple result);
void	multiply_tuple_by_scalar(const t_tuple a, const float s, t_tuple res);
t_bool	compare_floats(float a, float b);
float	vector_magnitude(const t_tuple vec);
short	normalize_vector(const t_tuple vec, t_tuple result);

#endif
