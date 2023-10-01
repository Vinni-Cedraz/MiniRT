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

t_buf	normalize_rgb_string(int rgb)
{
	const int	idx = (rgb > 255) | ((rgb < 0) << 1);
	const int	normalized_rgbs[] = {
		rgb, 255, 0
	};

	return (ft_simple_itoa(normalized_rgbs[idx]));
}
