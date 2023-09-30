/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:22:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/28 15:27:38 by vcedraz-         ###   ########.fr       */
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
	char		pxls_str[STR_LIMIT];
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";
	t_buf		t;

	ft_bzero(pxls_str, STR_LIMIT);
	pixels_to_str(canvas, pxls_str, &t);
	header = ft_fmt_str(
			ppm_header_fmt_str,
			ft_simple_itoa(canvas->width).buf,
			ft_simple_itoa(canvas->height).buf, pxls_str
			);
	return (ft_strjoin(header, ft_strdup(pxls_str)));
}

static void	pixels_to_str(const t_canvas *c, char *pxls_str, t_buf *t)
{
	int			i;
	int			j;
	int			accumulator;
	int			t_buf_len;

	i = 0;
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
			ft_strlcat(pxls_str, t->buf, t->len + 2);
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

	if (color[j] > 255)
		*t = ft_simple_itoa(255);
	else if (color[j] <= 0)
		*t = ft_simple_itoa(0);
	else
		*t = ft_simple_itoa(color[j]);
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
// 	char					pxls_str[STR_LIMIT];
// 	int						idx;
// 	int						len;
// 	t_canvas 				c;
// 	t_buf					t;
//
// 	c = create_canvas(20, 10);
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
//     for (int i = 0; i < c.width * c.height; i++) {
//         int eq = cr_expect_tuple_eq(c.pixels[i / c.width][i % c.width],
// 		(t_tuple){1.0, 0.8, 0.6, COLOR});
//         cr_assert_eq(eq, TRUE);
//     }
// 	idx = -1;
// 	while (++idx < c.width * c.height)
// 	{
// 		for (int i = 0; i < 3; i++) {
// 			color_to_string(&c, idx, i, &t);
// 			cr_expect_str_eq(t.buf, expected_string[i]);
// 			len = ft_strlen(pxls_str) + ft_strlen(t.buf) + 2;
// 			ft_strlcat(pxls_str, t.buf, len);
// 		}
// 	}
// 	destroy_canvas(&c);
// }
//
// Test(canvas_to_ppm_aux_functions,
// pixels_string_being_initialized_with_correct_line_breaks,
// .description = CYAN"\npixels_to_string aux function test"RESET)
// {
//
// 	const t_canvas 				c = create_canvas(2, 10);
//
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
// 	t_constr pxls_str = canvas_to_ppm(&c);
// 	create_ppm_file(pxls_str, "./src/canvas/outfile.ppm");
// 	destroy_canvas(&c);
// }