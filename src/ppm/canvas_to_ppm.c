/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:22:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/01 09:58:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <string.h>

static char		*pixels_to_str(const t_canvas *c, char *pxls_str, t_buf *str);
t_buf			color_to_string(const t_canvas *c, int i, int j, t_buf *t);
void			concat_space(int *accumulator, t_buf *t);
void			concat_linebreak(char *pxls_str, int *accum);

char	*canvas_to_ppm(const t_canvas *canvas)
{
	char		*header;
	char		*pxls_str;
	t_buf		str;
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";

	pxls_str = calloc(canvas->width * canvas->height * 12, sizeof(char) + 2);
	pxls_str = pixels_to_str(canvas, pxls_str, &str);
	header = ft_fmt_str(
			ppm_header_fmt_str,
			ft_simple_itoa(canvas->width).buf,
			ft_simple_itoa(canvas->height).buf,
			pxls_str);
	return (ft_strjoin(header, pxls_str));
}

static char	*pixels_to_str(const t_canvas *c, char *pxls_str, t_buf *str)
{
	int	i;
	int	j;
	int	accumulator;
	int	pxls_str_len;
	int	last_len;

	i = 0;
	accumulator = 0;
	pxls_str_len = 0;
	while (i < c->width * c->height)
	{
		j = -1;
		while (++j < 3)
		{
			*str = color_to_string(c, i, j, str);
			accumulator += str->len + 1;
			last_len = pxls_str_len;
			pxls_str_len += strlen(pxls_str + pxls_str_len);
			concat_space(&accumulator, str);
			strcat(pxls_str + last_len, str->buf);
		}
		if (!(++i % c->width))
			concat_linebreak(pxls_str, &accumulator);
	}
	return (pxls_str);
}

// #include "../tests/tester.h"
//
// t_constr expected_string[] = {"255", "204", "153"};
//
// Test(canvas_to_ppm_aux_functions,
// 	each_color_string_being_initialized_individually,
// 		.description = CYAN"\nconvert_color_to_string aux function test"RESET)
// {
//
// 	int						idx;
// 	t_canvas 				c;
// 	t_buf					t;
//
// 	c = create_canvas(20, 10);
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
//     for (int i = 0; i < c.width * c.height; i++) {
//         cr_expect_tuple_eq(c.pixels[i / c.width][i % c.width],
// 		(t_tuple){1.0, 0.8, 0.6, COLOR});
//     }
// 	idx = -1;
// 	while (++idx < c.width * c.height)
// 	{
// 		for (int i = 0; i < 3; i++) {
// 			color_to_string(&c, idx, i, &t);
// 			cr_expect_str_eq(t.buf, expected_string[i]);
// 		}
// 	}
// 	destroy_canvas(&c);
// }
//
// Test(canvas_to_ppm_aux_functions,
// 	creating_outfile,
// 			.description = CYAN"\ncanvas_to_ppm speed test"RESET)
// {
// 	const t_canvas 				c = create_canvas(1080, 1920);
//
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
// 	t_constr pxls_str = canvas_to_ppm(&c);
// 	create_ppm_file(pxls_str);
// 	destroy_canvas(&c);
// }
