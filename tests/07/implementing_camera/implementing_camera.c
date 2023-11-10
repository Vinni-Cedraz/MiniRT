#include "tester.h"

// Scenario : Constructing a camera
#define scenario1                                                                                                      \
    CYAN "Given hsize ← 160 \\n"                                                                                     \
         "And vsize ← 120\n"                                                                                         \
         "And field_of_view ← π/2\n"                                                                                \
         "When c ← camera(hsize, vsize, field_of_view)\n"                                                            \
         "Then c.hsize = 160\n"                                                                                        \
         "And c.vsize = 120\n"                                                                                         \
         "And c.field_of_view = π/2\n"                                                                                \
         "And c.transform = identity_matrix\n" RESET

Test(camera, implementing_a_camera, .description = scenario1) {
    int hsize = 160;
    int vsize = 120;
    float field_of_view = M_PI / 2;
    const t_camera c = create_camera(hsize, vsize, field_of_view);

    cr_expect_eq(c.hsize, 160);
    cr_expect_eq(c.vsize, 120);
    cr_expect_eq(floats_eq(c.field_of_view, M_PI / 2), TRUE);
    cr_expect_matrices_eq(c.transform, create_identity_matrix());
}

// Scenario: The pixel size for a horizontal canvas
#define scenario2                                                                                                      \
    CYAN "Given c ← camera(200, 125, π/2)\n"                                                                        \
         "Then c.pixel_size = 0.01" RESET

Test(camera, horizontal_pixel_size, .description = scenario2) {
    const t_camera c = create_camera(200, 125, M_PI / 2);
    cr_expect_eq(floats_eq(c.pixel_size, 0.01), TRUE);
}

// Scenario: The pixel size for a vertical canvas
#define scenario3                                                                                                      \
    CYAN "Scenario: The pixel size for a vertical canvas\n"                                                            \
         "Given c ← camera(125, 200, π/2)\n"                                                                        \
         "Then c.pixel_size = 0.01" RESET

Test(camera, vertical_pixel_size, .description = scenario3) {
    const t_camera c = create_camera(200, 125, M_PI / 2);
    cr_expect_eq(floats_eq(c.pixel_size, 0.01), TRUE);
}

// Scenario: Constructing a ray through the center of the canvas
#define scenario4                                                                                                      \
    CYAN "Given c ← camera(201, 101, π/2)\n"                                                                        \
         "When r ← ray_for_pixel(c, 100, 50)\n"                                                                      \
         "Then r.origin = point(0, 0, 0)\n"                                                                            \
         "And r.direction = vector(0, 0, -1)" RESET
// ERROR
Test(camera, ray_for_pixel_center, .description = scenario4) {
    const t_camera c = create_camera(201, 101, M_PI / 2);
    const t_ray r = ray_for_pixel(c, 100, 50);
    cr_expect_eq(tuples_eq(r.origin, (t_tuple){0, 0, 0, POINT}), TRUE);
    cr_expect_eq(tuples_eq(r.direction, (t_tuple){0, 0, -1, VECTOR}), TRUE);
}

// Scenario: Constructing a ray through a corner of the canvas
#define scenario5                                                                                                      \
    CYAN "Given c ← camera(201, 101, π/2)\n"                                                                        \
         "When r ← ray_for_pixel(c, 0, 0)\n"                                                                         \
         "Then r.origin = point(0, 0, 0)\n"                                                                            \
         "And r.direction = vector(0.66519, 0.33259, -0.66851)" RESET
// ERROR
Test(camera, ray_through_a_corner, .description = scenario4) {
    const t_camera c = create_camera(201, 101, M_PI / 2);
    const t_ray r = ray_for_pixel(c, 0, 0);
    cr_expect_eq(tuples_eq(r.origin, (t_tuple){0, 0, 0, POINT}), TRUE);
    cr_expect_eq(tuples_eq(r.direction, (t_tuple){0.6651, 0.3325, -0.6685, VECTOR}), TRUE);
}
// Scenario: Constructing a ray when the camera is transformed
#define scenario6                                                                                                      \
    CYAN "Given c ← camera(201, 101, π/2)\n"                                                                        \
         "When c.transform ← rotation_y(π/4) * translation(0, -2, 5)\n"                                             \
         "And r ← ray_for_pixel(c, 100, 50)\n"                                                                       \
         "Then r.origin = point(0, 2, -5)\n"                                                                           \
         "And r.direction = vector(√2/2, 0, -√2/2)" RESET

Test(camera, ray_when_camera_transformed, .description = scenario6) {
    t_camera c = create_camera(201, 101, M_PI / 2);
    c.transform = mult_matrices(
			create_y_rotation_matrix(M_PI / 4),
			create_translation_matrix((t_tuple){0, -2, 5, POINT})\
	);
    const t_ray r = ray_for_pixel(c, 100, 50);
    cr_expect_eq(tuples_eq(r.origin, (t_tuple){0, 2, -5, POINT}), TRUE);
    cr_expect_eq(tuples_eq(r.direction, (t_tuple){sqrt(2) / 2, 0, -sqrt(2) / 2, VECTOR}), TRUE);
}

// Scenario: Rendering a world with a camera
# define scenario6 CYAN \
"Given w ← default_world()\n"         \
"And c ← camera(11, 11, π/2)\n"         \
"And from ← point(0, 0, -5)\n"         \
"And to ← point(0, 0, 0)\n"         \
"And up ← vector(0, 1, 0)\n"         \
"And c.transform ← view_transform(from, forward, up)\n"         \
"When image ← render(c, w)\n"         \
"Then pixel_at(image, 5, 5) = color(0.38066, 0.47583, 0.2855)" RESET 

Test(camera, rendering_a_world, .description = scenario6)
{
	const t_world w = default_world();

	t_canvas image;
	t_tuple forward;
	t_camera c = create_camera(11, 11, M_PI / 2);
	t_tuple from = (t_tuple){0, 0, -5, POINT};
	t_tuple to = (t_tuple){0, 0, 0, POINT};
	t_tuple up = (t_tuple){0, 1, 0, VECTOR};

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	normalize(up, up);
	c.transform = view_transform(from, forward, up);
	image = render(c, w);
	cr_expect_eq(tuples_eq(image.pixels[5][5], (t_tuple){0.3806, 0.4758, 0.2855, COLOR}), TRUE);
}
