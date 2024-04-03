#include "tester.h"
#include <criterion/internal/test.h>

#define scenario1 CYAN "\n Draw a pixel for each hour in a clock" RESET

const t_tuple	origin = {
		540, 960, 0, POINT
};
t_tuple		twelve_o_clock = {
		0, -450, 0, POINT };
const t_tuple WHITE  = {1, 1, 1, COLOR};

#define scenario2 CYAN "\n Given canvas(1080, 1920)\n"  \
					"And twelve_o'clock(0, -450)\n"            \
					"And R <- create_z_rotation_matrix(π/6)\n" \
					"Then translate_coordinate(twelve_o'clock * R) -> (one o clock)\n" RESET


// Test(putting_it_together, drawing_twelve_of_clock_and_one_o_clock, .description = scenario2) {
//
// 	t_canvas 	canvas;
// 	t_tuple		next_hour;
//
// 	canvas = create_canvas(1080, 1920);
// 	t_matrix Rz = create_z_rotation_matrix((M_PI / 6));
//
// 	multiply_tuple_by_matrix(twelve_o_clock, Rz, next_hour);
// 	translate_coordinate(next_hour, &canvas, next_hour);
// 	translate_coordinate(twelve_o_clock, &canvas, twelve_o_clock);
// 	write_pixel(&canvas, twelve_o_clock[Y], twelve_o_clock[X], WHITE);
// 	write_pixel(&canvas, next_hour[Y], next_hour[X], WHITE);
//
// 	t_constr str = canvas_to_ppm(&canvas);
//     create_ppm_file(str);
// }

#define scenario3 CYAN "\n Given canvas(1080, 1920)\n"  \
					"And twelve_o'clock(0, -450)\n"            \
					"And R <- create_z_rotation_matrix(π/6)\n" \
					"Then draw_clock(twelve_o'clock, R, canvas) -> (draws a whole clock)\n" RESET

Test(putting_it_together, drawing_whole_clock, .description = scenario3) {

	t_canvas 	canvas;
	t_tuple		next_hour;
	t_tuple		hour = {
		0, -450, 0, POINT };
	int i = 12;
	double twelve_o_clock_arr[4];
	double next_hour_arr[4];

	canvas = create_canvas(1080, 1920);
	t_matrix Rz = create_z_rotation_matrix((M_PI / 6));
	tuple_to_arr(twelve_o_clock, twelve_o_clock_arr);
	translate_coordinate(twelve_o_clock_arr, &canvas, twelve_o_clock_arr);
	write_pixel(&canvas, twelve_o_clock.y, twelve_o_clock.x, (double[4]){1, 1, 1, COLOR});
	while (--i)
	{
		next_hour = multiply_tuple_by_matrix(hour, Rz);
		hour.x = next_hour.x;
		hour.y = next_hour.y;
		hour.z = next_hour.z;
		hour.w = next_hour.w;
		translate_coordinate(next_hour_arr, &canvas, next_hour_arr);
		write_pixel(&canvas, next_hour.y, next_hour.x, (double[4]){1, 1, 1, COLOR});
	}
	t_constr str = canvas_to_ppm(&canvas);
    create_ppm_file(str, "clock.ppm");
}
