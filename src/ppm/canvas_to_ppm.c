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

static void	pixels_to_str(const t_canvas *c, char *pxls_str, t_buf *t);
static void	color_to_string(const t_canvas *c, int i, int j, t_buf *t);
static void	concat_space(int *accumulator, t_buf *t);
static void	concat_linebreak(char *pxls_str, int *accum, t_buf *t);

char	*canvas_to_ppm(const t_canvas *canvas)
{
	char		*header;
	char		*pxls_str;
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";
	t_buf		t;

	pxls_str = ft_calloc(canvas->width * canvas->height * 12, sizeof(char) + 2);
	pixels_to_str(canvas, pxls_str, &t);
	header = ft_fmt_str(
			ppm_header_fmt_str,
			ft_simple_itoa(canvas->width).buf,
			ft_simple_itoa(canvas->height).buf,
			pxls_str);
	return (ft_strjoin(header, pxls_str));
}

static void	pixels_to_str(const t_canvas *c, char *pxls_str, t_buf *t)
{
	int			i;
	int			j;
	int			accumulator;
	int			t_buf_len;

	i = 0;
	accumulator = 0;
	while (i < c->width * c->height)
	{
		j = 0;
		while (j < 3)
		{
			color_to_string(c, i, j, t);
			t_buf_len = ft_strlen(t->buf);
			accumulator += t_buf_len + 1;
			t->len = t_buf_len + ft_strlen(pxls_str) + 2;
			concat_space(&accumulator, t);
			ft_strlcat(pxls_str, t->buf, t->len);
			j++;
		}
		if (0 == ++i % c->width)
			concat_linebreak(pxls_str, &accumulator, t);
	}
}

static void	concat_linebreak(char *pxls_str, int *accum, t_buf *t)
{
	ft_memmove(pxls_str + ft_strlen(pxls_str) - 1, "\0", 1);
	ft_strlcat(pxls_str, "\n", t->len + 2);
	*accum = 0;
}

static void	concat_space(int *accumulator, t_buf *t)
{
	if (*accumulator >= 67)
	{
		ft_strlcat(t->buf, "\n", t->len);
		*accumulator = 0;
		return ;
	}
	ft_strlcat(t->buf, " ", t->len);
}

static void	color_to_string(const t_canvas *c, int i, int j, t_buf *t)
{
	const int	w = c->width;
	const int	color[] = {
		(int)ceil(c->pixels[i / w][i % w][R] * 255),
		(int)ceil(c->pixels[i / w][i % w][G] * 255),
		(int)ceil(c->pixels[i / w][i % w][B] * 255),
	};

	*t = normalize_rgb_string(color[j]);
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
// 		.timeout = 1,
// 			.description = CYAN"\ncanvas_to_ppm speed test"RESET)
// {
// 	const t_canvas 				c = create_canvas(100, 100);
//
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
// 	t_constr pxls_str = canvas_to_ppm(&c);
// 	create_ppm_file(pxls_str, "$HOME/MiniRT/src/ppm/CANVAS.ppm");
// 	destroy_canvas(&c);
// }
