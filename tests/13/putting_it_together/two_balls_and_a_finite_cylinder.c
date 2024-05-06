#include "../../tester.h"

Test(two_balls_and_a_cylinder, two_balls_and_a_cylinder) {
	t_shape	cyl = create_cylinder();
	t_shape	right_ball = create_sphere();
	t_shape	left_ball = create_sphere();

	cyl.material.color = create_tuple(1, 0, 0, COLOR);
	right_ball.material.color = create_tuple(1, 0, 0, COLOR);
	left_ball.material.color = create_tuple(1, 0, 0, COLOR);
	set_cyl_min_max(&cyl, -10, 5);
	set_transform((t_shape *)&right_ball, mult_matrices(
				create_translation_matrix((t_tuple){2.75, 0, 0, POINT}),
				create_scaling_matrix(1.5, 1.5, 1.5))
	);

	set_transform((t_shape *)&left_ball, mult_matrices(
				create_translation_matrix((t_tuple){-2.75, 0, 0, POINT}),
				create_scaling_matrix(1.5, 1.5, 1.5))
	);

	t_world world;
    world.shapes = malloc(sizeof(t_shape) * 3);
	world.shapes[0] = cyl;
	world.shapes[1] = right_ball;
	world.shapes[2] = left_ball;
    world.fixed_count = 3;

    world.light = (t_point_light) {
        {10, 25, 10, POINT},
        {1, 1, 1, COLOR},
    };

    t_camera camera = create_camera(480, 280, M_PI / 3);
    t_tuple from = (t_tuple){0, -15, 5, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    forward = subtract_tuples(to, from);
    forward = normalize(forward);
    camera.transform = view_transform(from, forward, up);
	mlx_t *mlx;

	mlx = mlx_init(SIZEW, SIZEH, "classic obscene test", 0);
	world.image = create_image(mlx);
    render(world.image, world);
	mlx_image_to_window(mlx, world.image, 0, 0);
	mlx_loop(mlx);
}
