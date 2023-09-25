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

static void	pixels_to_str(const t_canvas *canvas, char *pxls_str);

char	*canvas_to_ppm(const t_canvas *canvas)
{
	char		*header;
	char		pxls_str[STR_LIMIT];
	const char	*w = ft_itoa(canvas->width);
	const char	*h = ft_itoa(canvas->height);
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";

	pixels_to_str(canvas, pxls_str);
	header = ft_fmt_str(ppm_header_fmt_str, w, h, pxls_str);
	return (header);
}

static void	pixels_to_str(const t_canvas *canvas, char *pxls_str)
{
	const char				*pxl_fmt_str;
	const unsigned short	w = canvas->width;
	char					*pxl_str;
	int						i;

	pxl_fmt_str = "%d %d %d\n";
	i = 0;
	while (i < canvas->width * canvas->height)
	{
		pxl_str = ft_fmt_str(pxl_fmt_str,
				ft_itoa((int)(canvas->pixels[i / w][i % w][R] * 255)),
				ft_itoa((int)(canvas->pixels[i / w][i % w][G] * 255)),
				ft_itoa((int)(canvas->pixels[i / w][i % w][G] * 255)));
		ft_strlcat(pxls_str, pxl_str, ft_strlen(pxls_str));
		free(pxl_str);
		i++;
	}
}
