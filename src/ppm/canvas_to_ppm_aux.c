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
	const int	normalized_rgbs[] = {rgb, 255, 0};
	const int	idx = (rgb > 255) | ((rgb < 0) << 1);

	return (ft_simple_itoa(normalized_rgbs[idx]));
}

void	concat_linebreak(char *pxls_str, int *accum)
{
	memmove(pxls_str + strlen(pxls_str) - 1, "\0", 1);
	strcat(pxls_str, "\n");
	*accum = 0;
}

void	concat_space(int *accumulator, t_buf *str)
{
	if (*accumulator >= 67)
	{
		strcat(str->buf, "\n");
		*accumulator = 0;
		return ;
	}
	strcat(str->buf, " ");
}

t_buf	color_to_string(const t_canvas *c, int i, int j, t_buf *str)
{
	const int	w = c->width;
	const int	color[] = {
		(int)ceil(c->pixels[i / w][i % w][R] * 255),
		(int)ceil(c->pixels[i / w][i % w][G] * 255),
		(int)ceil(c->pixels[i / w][i % w][B] * 255),
	};

	return (normalize_rgb_string(color[j]));
}
