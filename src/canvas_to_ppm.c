/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:10:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/25 18:26:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

const char	*canvas_to_ppm(const t_canvas *canvas)
{
	const char	*w = ft_itoa(canvas->width);
	const char	*h = ft_itoa(canvas->height);
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";
	const char	*header = ft_fmt_str(ppm_header_fmt_str, w, h, NULL);

	return (header);
}
