/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:59:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/07 10:07:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_4x4_matrix(t_matrix *m)
{
	(void)m;
	return (t_matrix){0};
}

t_3x3matrix	create_3x3_matrix(t_3x3matrix *m)
{
	(void)m;
	return (t_3x3matrix){0};
}

t_2x2matrix	create_2x2_matrix(t_2x2matrix *m)
{
	(void)m;
	return (t_2x2matrix){0};
}

t_matrix	create_identity_matrix(void)
{
	return (t_matrix){0};
}
