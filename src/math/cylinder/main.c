#include "../tests/tester.h"

int main() {
	t_cylinder	cyl = create_cylinder();
	t_sphere	right_ball = create_sphere();
	t_sphere	left_ball = create_sphere();

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, -5, 1);
	set_transform((t_shape *)&right_ball, mult_matrices(
				create_translation_matrix((t_tuple){2.75, 0, 0}),
				create_scaling_matrix(1.5, 1.5, 1.5)));
	set_transform((t_shape *)&left_ball, mult_matrices(
				create_translation_matrix((t_tuple){-2.75, 0, 0}),
				create_scaling_matrix(1.5, 1.5, 1.5)));

	t_world world;
    world.objs = malloc(sizeof(t_shape) * 3);
	world.objs[0] = *(t_shape *)&cyl;
	world.objs[1] = *(t_shape *)&right_ball;
	world.objs[2] = *(t_shape *)&left_ball;
    world.count = 3;


    world.light = &(t_point_light) {
        {10, 25, 10, POINT},
        {1, 0, 0, COLOR},
    };

    t_camera camera = create_camera(480, 280, M_PI / 4);
    t_tuple from = (t_tuple){-7.5, -15, 10, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 0, 1, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, world);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "main.ppm");
    destroy_canvas(&c);
	free(str);
	free(world.objs);
}
