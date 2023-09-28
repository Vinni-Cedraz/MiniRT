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

static void	pixels_to_str(const t_canvas *canvas, char ps[], char p[5]);
static void	color_to_string(const t_canvas *c, int i, int j, char k[]);

char	*canvas_to_ppm(const t_canvas *canvas)
{
	char		*header;
	char		pxls_str[STR_LIMIT];
	char		w[STR_LIMIT];
	char		h[STR_LIMIT];
	const char	ppm_header_fmt_str[35] = "P3\n%s %s\n255\n";

	ft_simple_itoa(canvas->width, w);
	ft_simple_itoa(canvas->width, h);
	pixels_to_str(canvas, pxls_str, "");
	header = ft_fmt_str(ppm_header_fmt_str, w, h, pxls_str);
	return (ft_strjoin(header, ft_strdup(pxls_str)));
}

static void	pixels_to_str(const t_canvas *canvas, char pxls_str[],
		char pxl_str[5])
{
	int	i;
	int	j;
	int	l;
	int	pxl_str_len;
	int	pxls_str_len;

	i = 0;
	ft_bzero(pxls_str, STR_LIMIT);
	while (i < canvas->width * canvas->height)
	{
		j = 0;
		while (j < 3)
		{
			pxl_str_len = ft_strlen(pxl_str);
			pxls_str_len = ft_strlen(pxls_str);
			color_to_string(canvas, i, j, pxl_str);
			l = pxl_str_len + pxls_str_len + 2;
			ft_strlcat(pxls_str, pxl_str, l);
		}
		i++;
	}
}

static void	color_to_string(const t_canvas *c, int i, int j, char pxl_str[])
{
	const int	w = c->width;
	const int	color[] = {
		(int)ceil(c->pixels[i / w][i % w][R] * 255),
		(int)ceil(c->pixels[i / w][i % w][G] * 255),
		(int)ceil(c->pixels[i / w][i % w][B] * 255),
	};

	ft_simple_itoa(color[j], pxl_str);
}

// #include "tester.h"
//
// t_constr expected_string[] = {"255", "204", "153"};
//
// Test(canvas_to_ppm_aux_functions,
// 	each_color_string_being_initialized_individually,
// 		.description = CYAN"\nconvert_color_to_string aux function test"RESET) {
//
// 	char					pxls_str[STR_LIMIT];
// 	char					pxl_str[5];
// 	int						idx;
// 	int						len;
// 	t_canvas 				c;
//
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
//
// 			color_to_string(&c, idx, i, pxl_str);
// 			cr_expect_str_eq(pxl_str, expected_string[i]);
// 			len = ft_strlen(pxls_str) + ft_strlen(pxl_str) + 2;
// 			ft_strlcat(pxls_str, pxl_str, len);
// 		}
// 	}
// 	destroy_canvas(&c);
// }
//
// Test(canvas_to_ppm_aux_functions, pixels_string_being_initialized_with_correct_line_breaks,
// 		.description = CYAN"\npixels_to_string aux function test"RESET) {
// }
