#include "tester.h"

#define suite_name canvas
void create_ppm_file(t_constr ppm_string, const char filename[]);

//  =======================================================================  //
//                         Scenario: creating a canvas                       //
//  =======================================================================  //
#define scenario1                                                                        \
    CYAN "\n"                                                                            \
         "Given c ← canvas(20, 10)\n"                                                    \
         "Then c.width = 10 And c.height = 20\n"                                         \
         "And every pixel of c is color(0, 0, 0)" RESET

Test(suite_name, creating_a_canvas, .description = scenario1) {
    const t_canvas c = create_canvas(20, 10);
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
#define scenario2                                                                        \
    CYAN "\n"                                                                            \
         "Given c ← canvas(20, 10)\n"                                                    \
         "When write_pixel(c, 2, 3, red)\n"                                              \
         "Then pixel_at(c, 2, 3) = red" RESET

Test(suite_name, writing_a_pixel_in_a_canvas, .description = scenario2) {
    t_canvas c = create_canvas(20, 10);
    write_pixel(&c, 3, 2, (t_tuple){1, 0, 0, COLOR});
    int eq = cr_expect_tuple_eq(c.pixels[3][2], (t_tuple){1, 0, 0, COLOR});
    cr_expect_eq(eq, TRUE);
}

//  =======================================================================  //
//               Scenario: Constructing the PPM header                       //
//  =======================================================================  //
#define scenario3                                                                        \
    CYAN "\n"                                                                            \
         "Given c ← canvas(3, 5)\n"                                                      \
         "When ppm ← canvas_to_ppm(c)\n"                                                 \
         "Then lines 1-3 of ppm are:\n"                                                  \
         "P3\n"                                                                          \
         "5 3\n"                                                                         \
         "255" RESET

Test(suite_name, constructing_the_ppm_header, .description = scenario3) {
    const char expected[] = "P3\n5 3\n255\n"; // "P3\n" and "255\n" are fixed for all ppm
                                              // files in this project
    const t_canvas c = create_canvas(3, 5);
    const char *ppm_canvas_full = canvas_to_ppm(&c);
    char ppm_header[12];
    ft_strlcpy(ppm_header, ppm_canvas_full, 12);
    cr_expect_str_eq(ppm_header, expected);
}

//  =======================================================================  //
//               Scenario: Constructing the PPM pixel data                   //
//  =======================================================================  //
#define scenario4                                                                      \
    CYAN "\nGiven c ← canvas(3, 5)\n"                                                  \
         "And c1 ← color(1.0, 0, 0)\n"                                                 \
         "And c2 ← color(0, 0.5, 0)\n"                                                 \
         "And c3 ← color(-0.5, 0, 1)\n"                                                \
         "When write_pixel(c, 0, 0, c1)\n"                                             \
         "And write_pixel(c, 2, 1, c2)\n"                                              \
         "And write_pixel(c, 4, 2, c3)\n"                                              \
         "And ppm ← canvas_to_ppm(c)\n"                                                \
         "Then lines 4-6 of ppm are\n"                                                 \
         "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"                                           \
         "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"                                           \
         "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255" RESET

Test(suite_name, writing_the_whole_canvas_on_the_ppm_string, .description = scenario4) {
    t_canvas c = create_canvas(3, 5);
    const char expected[] = "P3\n5 3\n255\n"
                            "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                            "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                            "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

    write_pixel(&c, 0, 0, (t_tuple){1.5, 0, 0, COLOR});
    write_pixel(&c, 1, 2, (t_tuple){0, 0.5, 0, COLOR});
    write_pixel(&c, 2, 4, (t_tuple){0, -0.5, 1, COLOR});
    t_constr res = canvas_to_ppm(&c);
    cr_expect_str_eq(res, expected);
	create_ppm_file(res, "output_scenario4.ppm");
    destroy_canvas(&c);
}

#define scenario5                                                                        \
    CYAN "\nScenario: Splitting long lines in PPM files\n"                               \
         "Given c ← canvas(2, 10)\n"                                                     \
         "When every pixel of c is set to color(1, 0.8, 0.6)\n"                          \
         "And ppm ← canvas_to_ppm(c)\n"                                                  \
         "Then lines 4-7 of ppm are\n"                                                   \
         "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"         \
         "153 255 204 153 255 204 153 255 204 153 255 204 153\n"                         \
         "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"         \
         "153 255 204 153 255 204 153 255 204 153 255 204 153" RESET                     \

#define LINES 7
t_constr lines_to_assert[LINES] = {
            "P3\n",
			"10 2\n",
			"255\n",
			"255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n",
         	"153 255 204 153 255 204 153 255 204 153 255 204 153\n",
         	"255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n",
         	"153 255 204 153 255 204 153 255 204 153 255 204 153\n"
};

Test(suite_name, lines_longer_than_70_must_break, .description = scenario5) {
    t_canvas c;
	char *line;
   
    c = create_canvas(2, 10);
	set_all_pixels_to_one_color(&c, (t_tuple){1, 0.8, 0.6});
	t_constr ppm_string = canvas_to_ppm(&c);
	create_ppm_file(ppm_string, "output_scenario5.ppm");
	int fd = open("output_scenario5.ppm", O_RDONLY);
	for (int i = 0; i < LINES; i++)
	{
		line = ft_gnl(fd);
		cr_assert_str_eq(line, lines_to_assert[i]);
		free(line);
	}
    destroy_canvas(&c);
}
