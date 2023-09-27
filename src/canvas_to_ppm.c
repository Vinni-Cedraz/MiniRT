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
#include <stdio.h>

static void		pixels_to_str(const t_canvas *canvas, char *pxls_str);
static char		*fmt_s(const t_canvas *c, const int idx);
static void		convert_rgb_values_to_strings(const t_ints rgb, t_strings *s);
static void		free_t_strings(t_strings *strs);

char	*canvas_to_ppm(const t_canvas *canvas)
{
	char		*header;
	char		pxls_str[STR_LIMIT];
	const char	*w = ft_itoa(canvas->width);
	const char	*h = ft_itoa(canvas->height);
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";

	ft_bzero(pxls_str, STR_LIMIT);
	pixels_to_str(canvas, pxls_str);
	header = ft_fmt_str(ppm_header_fmt_str, w, h, pxls_str);
	free((void *)w);
	free((void *)h);
	return (ft_strjoin(header, ft_strdup(pxls_str)));
}

static void	pixels_to_str(const t_canvas *canvas, char *pxls_str)
{
	char					*pxl_str;
	int						idx;
	const unsigned short	w = canvas->width;
	int						len;

	idx = 0;
	while (idx < canvas->width * canvas->height)
	{
		pxl_str = fmt_s(canvas, idx);
		len = ft_strlen(pxls_str) + ft_strlen(pxl_str) + 2;
		ft_strlcat(pxls_str, pxl_str, len);
		free(pxl_str);
		idx++;
	}
}

static inline char	*fmt_s(const t_canvas *c, const int idx)
{
	char			*pxl_str;
	t_strings		*strings;
	const int		w = c->width;
	static t_constr fmt_str = "%s %s %s";
	const t_ints	ints = {
		(int)ceil(c->pixels[idx / w][idx % w][R] * 255),
		(int)ceil(c->pixels[idx / w][idx % w][G] * 255),
		(int)ceil(c->pixels[idx / w][idx % w][B] * 255),
	};

	strings = malloc(sizeof(t_strings));
	convert_rgb_values_to_strings(ints, strings);
	pxl_str = ft_fmt_str(fmt_str, strings->a, strings->b, strings->c);
	if (!((idx + 1) % w))
		pxl_str = ft_strjoin(pxl_str, ft_strdup("\n"));
	else
		pxl_str = ft_strjoin(pxl_str, ft_strdup(" "));
	free_t_strings(strings);
	return (pxl_str);
}

static void	convert_rgb_values_to_strings(const t_ints rgb, t_strings *strings)
{
	if (rgb.a > 255)
		strings->a = ft_itoa(255);
	else if (rgb.a < 0)
		strings->a = ft_itoa(0);
	else
		strings->a = ft_itoa(rgb.a);
	if (rgb.b > 255)
		strings->b = ft_itoa(255);
	else if (rgb.b < 0)
		strings->b = ft_itoa(0);
	else
		strings->b = ft_itoa(rgb.b);
	if (rgb.c > 255)
		strings->c = ft_itoa(255);
	else if (rgb.c < 0)
		strings->c = ft_itoa(0);
	else
		strings->c = ft_itoa(rgb.c);
}

void	free_t_strings(t_strings *strs)
{
	free((void *)strs->a);
	free((void *)strs->b);
	free((void *)strs->c);
	free(strs);
}
