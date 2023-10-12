#include "tester.h"
#include <criterion/internal/test.h>

#define scenario1 CYAN "\n Draw a pixel for each hour in a clock" RESET

const t_tuple	origin = {
		540, 960, 0, POINT
};
const t_tuple		twelve_o_clock = {
		100, 960, 0, POINT
};
const t_tuple WHITE  = {1, 1, 1, COLOR};

// Test(putting_it_together, drawing_a_point_in_the_middle, .description = scenario1) {
//
//  	t_canvas 		canvas;
//
// 	canvas = create_canvas(1080, 1920);
// 	write_pixel(&canvas, origin[X], origin[Y], WHITE);
// 	t_constr str = canvas_to_ppm(&canvas);
//     create_ppm_file(str);
// }

#define scenario2 CYAN "\n Given origin(540, 960)\n"  \
					"And twelve_o'clock(20, 960)\n"            \
					"And R <- create_z_rotation_matrix(π/6)\n" \
					"Then twelve_o'clock * R -> (visually right)\n" RESET

Test(putting_it_together, drawing_a_clock, .description = scenario2) {

	t_tuple 	res;
	t_canvas 	canvas;

	canvas = create_canvas(1080, 1920);
	const t_matrix Rz = create_z_rotation_matrix(2 * M_PI / 6);
	write_pixel(&canvas, twelve_o_clock[X], twelve_o_clock[Y], WHITE);

	print_4x4matrix(Rz);
	multiply_tuple_by_matrix(twelve_o_clock, Rz, res);
	printf(CYAN"tuple: \n"RESET);
	print_tuple(res);
	// write_pixel(&canvas, res[X], res[Y], WHITE);
	t_constr str = canvas_to_ppm(&canvas);
    create_ppm_file(str);
}
