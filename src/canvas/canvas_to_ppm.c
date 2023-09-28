/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:10:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/25 18:26:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		pixels_to_str(const t_canvas *canvas, char *pxls_str);
static t_constr convert_color_to_string(const t_canvas *c, int idx, int rgb);

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
	int						i;
	int						j;
	int						len;

	i= 0;
	while (i < canvas->width * canvas->height)
	{
		j = 0;
		while (j < 3)
		{
			t_constr pxl_str = convert_color_to_string(canvas, i, j);
			len = ft_strlen(pxls_str) + ft_strlen(pxl_str) + 2;
			ft_strlcat(pxls_str, pxl_str, len);
			free((void *)pxl_str);
		}
		i++;
	}
}

static t_constr convert_color_to_string(const t_canvas *c, int idx, int col_idx)
{
	const int		w = c->width;
	const int		color[] = {
		(int)ceil(c->pixels[idx / w][idx % w][R] * 255),
		(int)ceil(c->pixels[idx / w][idx % w][G] * 255),
		(int)ceil(c->pixels[idx / w][idx % w][B] * 255),
	};

	return (ft_itoa(color[col_idx]));
}

// #include "tester.h"
//
// t_constr expected_string[] = {"255", "204", "153"};
//
// Test(canvas_to_ppm, each_color_string_being_initialized_individually) {
// 	t_canvas c = create_canvas(20, 10);
//
// 	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
//     for (int i = 0; i < c.width * c.height; i++) {
//         int eq = cr_expect_tuple_eq(c.pixels[i / c.width][i % c.width], (t_tuple){1.0, 0.8, 0.6, COLOR});
//         cr_assert_eq(eq, TRUE);
//     }
// 	char					pxls_str[STR_LIMIT];
// 	int						idx;
// 	int						len;
//
// 	idx = 0;
// 	while (idx < c.width * c.height)
// 	{
// 		for (int i = 0; i < 3; i++) {
// 			t_constr pxl_str = convert_color_to_string(&c, idx, i);
// 			cr_expect_str_eq(pxl_str, expected_string[i]);
// 			len = ft_strlen(pxls_str) + ft_strlen(pxl_str) + 2;
// 			ft_strlcat(pxls_str, pxl_str, len);
// 			free((void *)pxl_str);
// 		}
// 		idx++;
// 	}
// 	destroy_canvas(&c);
// }
