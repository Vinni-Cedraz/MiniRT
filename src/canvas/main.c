#include "../tests/tester.h"

int main() {
        char pxls_str[STR_LIMIT];
        t_canvas c;

        c = create_canvas(40, 10);
        ft_bzero(pxls_str, STR_LIMIT);
        set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
		t_constr ppm_str = canvas_to_ppm(&c);
		printf("%s", ppm_str);
        destroy_canvas(&c);
}
