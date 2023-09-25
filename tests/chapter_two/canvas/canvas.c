#include "../../tester.h"

#define suite_name canvas

  //  =======================================================================  //
 //                         Scenario: creating a canvas                       //
//  =======================================================================  //
#define scenario1                                                                      \
    CYAN "\n"                                                                          \
         "Given c ← canvas(10, 20)\n"                                                  \
         "Then c.width = 10 And c.height = 20\n"                                       \
         "And every pixel of c is color(0, 0, 0) RESET"

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
