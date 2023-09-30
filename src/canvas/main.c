#include "../tests/tester.h"

static void color_to_string(const t_canvas *c, int i, int j, t_buf *t) {
    const int w = c->width;
    const int color[] = {
        (int)ceil(c->pixels[i / w][i % w][R] * 255),
        (int)ceil(c->pixels[i / w][i % w][G] * 255),
        (int)ceil(c->pixels[i / w][i % w][B] * 255),
    };

	printf("I- %d\n J- %d\n", i, j);
    if (color[j] > 255)
	{
		printf("Simple - 255\n");
        *t = ft_simple_itoa(255);
	}
    else if (color[j] <= 0)
	{
		printf("asldkaldka\n");
        *t = ft_simple_itoa(0);
	}
    else
	{
		printf("Simple color\n");
        *t = ft_simple_itoa(color[j]);
	}
}

t_constr expected_string[] = {"0", "0", "0"};

int main() {
    {

        char pxls_str[STR_LIMIT];
        int idx;
        int len;
        t_canvas c;
        t_buf t;

        c = create_canvas(9, 5);
        ft_bzero(pxls_str, STR_LIMIT);
        set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
        for (int i = 0; i < c.width * c.height; i++) {
            // int err = cr_expect_tuple_eq(c.pixels[i / c.width][i % c.width],
            // (t_tuple){0, 0, 0, COLOR});
            // printf("%d ", i);
            // print_tuple(c.pixels[i / c.width][i % c.width]);
            // cr_assert_eq(err, FALSE);
        }
        // return ;
        idx = -1;
        while (++idx < c.width * c.height) {
            for (int i = 0; i < 3; i++) {
                color_to_string(&c, idx, i, &t);
                len = ft_strlen(pxls_str) + ft_strlen(t.buf) + 3;
                ft_strlcat(pxls_str, t.buf, len + 1);
				printf("pxls_str => %s\n", pxls_str);
            }
        }
        destroy_canvas(&c);
    }
}
