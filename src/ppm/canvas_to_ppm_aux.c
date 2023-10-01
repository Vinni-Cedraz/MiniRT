/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:49:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/01 10:11:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

t_buf	normalize_rgb_string(int rgb)
{
	const int	idx = (rgb > 255) | ((rgb < 0) << 1);
	const int	normalized_rgbs[] = {rgb, 255, 0};

	return (ft_simple_itoa(normalized_rgbs[idx]));
}

void	concatenator(t_concatenator *x)
{
	const t_canvas	*c;
	int				i;
	int				t_buf_len;
	char			*pxls_str;

	c = x->c;
	i = x->i;
	pxls_str = x->res;
	while (*x->j < 3)
	{
		color_to_string(c, i, *x->j, &x->t);
		t_buf_len = strlen(x->t.buf);
		x->accumulator += t_buf_len + 1;
		x->t.len = t_buf_len + strlen(pxls_str);
		concat_space(x->accumulator, &x->t);
		strcat(pxls_str, x->t.buf);
		(*x->j)++;
	}
}
