#include "minirt.h"

int main() {
	t_shape	cyl = create_cylinder();
	// t_shape	right_ball = create_sphere();
	// t_shape	left_ball = create_sphere();

	cyl.material.color = create_tuple(1, 0, 0, COLOR);
	// right_ball.material.color = create_tuple(1, 0, 0, COLOR);
	// left_ball.material.color = create_tuple(1, 0, 0, COLOR);
	set_cyl_min_max(&cyl, -10, 5);
	// set_transform(&right_ball, mult_matrices(
	// 			create_translation_matrix((t_tuple){2.75, 0, 0, POINT}),
	// 			create_scaling_matrix(1.5, 1.5, 1.5))
	// );
	//
	// set_transform(&left_ball, mult_matrices(
	// 			create_translation_matrix((t_tuple){-2.75, 0, 0, POINT}),
	// 			create_scaling_matrix(1.5, 1.5, 1.5))
	// );

	t_world world;
    world.shapes = malloc(sizeof(t_shape) * 1);
	world.shapes[0] = cyl;
	// world.shapes[1] = right_ball;
	// world.shapes[2] = left_ball;
    world.fixed_count = 1;

    world.light = (t_point_light) {
        {5, 5, -5, POINT},
        {1, 1, 1, COLOR},
    };

    world.camera = create_camera(SIZEW, SIZEH, 85);
    t_tuple from = (t_tuple){0, 2, -4, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple forward;

    forward = normalize(subtract_tuples(to, from));
    world.camera.transform = view_transform(from, forward, world.camera.up);
	mlx_t *mlx;

	mlx = mlx_init(SIZEW, SIZEH, "classic obscene test", true);
	world.image = create_image(mlx);
    render(world.image, world);
	mlx_image_to_window(mlx, world.image, 0, 0);
	mlx_loop(mlx);
}
