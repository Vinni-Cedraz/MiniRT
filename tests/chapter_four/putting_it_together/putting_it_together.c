#include "tester.h"
#include <criterion/internal/test.h>

#define scenario2 CYAN "\n Draw a pixel for each hour in a clock" RESET

Test(putting_it_together, drawing_a_clock, .description = scenario) {

 	t_canvas 		canvas;
	const t_tuple	origin = {540, 960, 0, POINT};

	canvas = create_canvas(1080, 1920);
	write_pixel(&canvas, origin[X], origin[Y], (t_tuple){1, 1, 1, COLOR});
	t_constr str = canvas_to_ppm(&canvas);
    create_ppm_file(str);
}
