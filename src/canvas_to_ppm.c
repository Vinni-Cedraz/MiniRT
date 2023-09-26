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
		len = ft_strlen(pxls_str) + ft_strlen(pxl_str) + 1;
		ft_strlcat(pxls_str, pxl_str, len);
		free(pxl_str);
		idx++;
	}
}

static char	*fmt_s(const t_canvas *c, const int idx)
{
	char			*res;
	t_strings		*strings;
	const int		w = c->width;
	static t_string	fmt_str = "%s %s %s\n";
	const t_ints	ints = {
		(int)(c->pixels[idx / w][idx % w][R] * 255),
		(int)(c->pixels[idx / w][idx % w][G] * 255),
		(int)(c->pixels[idx / w][idx % w][B] * 255),
	};

	strings = malloc(sizeof(t_strings));
	convert_rgb_values_to_strings(ints, strings);
	res = ft_fmt_str(fmt_str, strings->a, strings->b, strings->c);
	free_t_strings(strings);
	return (res);
}

static void	convert_rgb_values_to_strings(const t_ints rgb, t_strings *strings)
{
	if (rgb.a <= 255)
		strings->a = ft_itoa(rgb.a);
	else
		strings->a = ft_itoa(255);
	if (rgb.b <= 255)
		strings->b = ft_itoa(rgb.b);
	else
		strings->b = ft_itoa(255);
	if (rgb.c <= 255)
		strings->c = ft_itoa(rgb.c);
	else
		strings->c = ft_itoa(255);
}

void	free_t_strings(t_strings *strs)
{
	free((void *)strs->a);
	free((void *)strs->b);
	free((void *)strs->c);
	free(strs);
}

// #include <stdio.h>
// #include <stdlib.h>
//
// // Define the t_canvas structure and required functions here
// // ...
//
// int main() {
//     // Create a sample t_canvas structure with some pixel data
//     t_canvas canvas = create_canvas(2, 2);
//     canvas.pixels[0][0][0] = 1.0;  // Red component
//     canvas.pixels[0][0][1] = 0.0;  // Green component
//     canvas.pixels[0][0][2] = 0.0;  // Blue component
//     canvas.pixels[0][1][0] = 0.0;
//     canvas.pixels[0][1][1] = 1.0;
//     canvas.pixels[0][1][2] = 0.0;
//     canvas.pixels[1][0][0] = 0.0;
//     canvas.pixels[1][0][1] = 0.0;
//     canvas.pixels[1][0][2] = 1.0;
//     canvas.pixels[1][1][0] = 1.0;
//     canvas.pixels[1][1][1] = 1.0;
//     canvas.pixels[1][1][2] = 1.0;
//
//     // Call the canvas_to_ppm function
//     char *ppm = canvas_to_ppm(&canvas);
//
//     // Print the resulting PPM header
//     printf("%s", ppm);
//
//     // Remember to free the allocated memory
//     free(ppm);
// 	destroy_canvas(&canvas);
// }
