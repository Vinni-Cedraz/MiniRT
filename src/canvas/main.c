#include "canvas_to_ppm.c"
#include "tester.h"

int main() {
	// char						pxls_str[STR_LIMIT];
	const t_canvas 				c = create_canvas(20, 10);

	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
	char *ppm = canvas_to_ppm(&c);
	printf("%s\n", ppm);
	destroy_canvas(&c);
}
