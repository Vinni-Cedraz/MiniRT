#include "../../tester.h"

#define suite_name canvas

  //  =======================================================================  //
 //                         Scenario: creating a canvas                       //
//  =======================================================================  //
#define scenario1                                                                      \
    CYAN "\n"                                                                          \
         "Given c ← canvas(10, 20)\n"                                                  \
         "Then c.width = 10 And c.height = 20\n"                                       \
         "And every pixel of c is color(0, 0, 0)" RESET

Test(suite_name, creating_a_canvas, .description = scenario1) {
    const t_canvas c = create_canvas(10, 20);
    cr_expect_eq(c.width, 10);
    cr_expect_eq(c.height, 20);
    for (int i = 0; i < c.width * c.height; i++) {
        int eq = cr_expect_tuple_eq(c.pixels[i / c.width][i % c.width], (t_tuple){0, 0, 0, COLOR});
        cr_assert_eq(eq, TRUE);
    }
}

  //  =======================================================================  //
 //                   Scenario: Writing a pixel to a canvas                   //
//  =======================================================================  //
#define scenario2                                                                      \
    CYAN "\n"                                                                          \
         "Given c ← canvas(10, 20)\n"                                                  \
         "When write_pixel(c, 2, 3, red)\n"                                            \
         "Then pixel_at(c, 2, 3) = red" RESET

Test(suite_name, writing_a_pixel_in_a_canvas, .description = scenario2) {
	t_canvas c = create_canvas(10, 20);
	write_pixel(&c, 2, 3, (t_tuple){1, 0, 0, COLOR});
	int eq = cr_expect_tuple_eq(c.pixels[2][3], (t_tuple){1, 0, 0, COLOR});
	cr_expect_eq(eq, TRUE);
}

  //  =======================================================================  //
 //               Scenario: Constructing the PPM header                       //
//  =======================================================================  //
#define scenario3                                                            \
        CYAN "\n"                                                            \
             "Given c ← canvas(5, 3)\n"                                      \
             "When ppm ← canvas_to_ppm(c)\n"                                 \
             "Then lines 1-3 of ppm are:\n"                                  \
             "P3\n" "5 3\n" "255\n" RESET

Test(suite_name, saving_a_canvas, .description = scenario3) {
 	// "P3\n" and "255\n" are fixed for all ppm files in this project
	const char expected[] ="P3\n5 3\n255\n";
	const t_canvas c  = create_canvas(5, 3);
	const char *ppm_header = canvas_to_ppm(&c);
	cr_expect_str_eq(ppm_header, expected);
}
