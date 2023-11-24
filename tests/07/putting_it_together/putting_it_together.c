#include "minirt.h"
#include "tester.h"

Test(putting_it_together, three_spheres)
{
    t_sphere left_ball = create_sphere();
    t_sphere right_ball = create_sphere();
    t_sphere middle_ball = create_sphere();
	t_sphere floor = create_sphere();
	t_sphere left_wall = create_sphere();
	t_sphere right_wall = create_sphere();
    t_world  world;

	t_matrix translation = create_translation_matrix((t_tuple){0, 0, -1, POINT});
 	t_matrix scaling = create_scaling_matrix(10, 0.01, 10);

	// FLOOR
	floor.material = create_material();
	init_tuple((t_tuple){1, 0.9, 0.9, COLOR}, floor.material.color);
	floor.material.specular = 0;
	set_transform((t_shape *)&floor, create_scaling_matrix(10, 0.01, 10));

	// BALLS
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.5, 1, 0.1}, &right_ball.material);
	set_transform((t_shape *)&right_ball, mult_matrices(
				create_translation_matrix((t_tuple){1.15, 0.7, 0.5}),
				create_scaling_matrix(0.5, 0.5, 0.5))
	);

    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.1, 1, 0.1}, &middle_ball.material);
	set_transform((t_shape *)&middle_ball, mult_matrices(
				create_translation_matrix((t_tuple){0, 0.8, 0.1}),
				create_scaling_matrix(0.7, 0.7, 0.7))
	);

	set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0.8, 0.1}, &left_ball.material);
	set_transform((t_shape *)&left_ball, mult_matrices(
				create_translation_matrix((t_tuple){-0.95, 0.33, 0.4}),
				create_scaling_matrix(0.33, 0.33, 0.33))
	);

	// LEFT_WALL
 	t_matrix y_rotation = create_y_rotation_matrix(-M_PI / 4);
 	t_matrix x_rotation = create_x_rotation_matrix(M_PI / 2);
	set_transform(
			(t_shape *)&left_wall,
			chain_transformations((t_matrix *[]){&scaling, &x_rotation, &y_rotation, &translation, NULL})
	);
	left_wall.material = floor.material;

	// RIGHT_WALL
 	y_rotation = create_y_rotation_matrix(M_PI / 4);
	set_transform(
			(t_shape *)&right_wall,
			chain_transformations((t_matrix *[]){&scaling, &x_rotation, &y_rotation, &translation, NULL})
	);
	right_wall.material = floor.material;

    world.objs = malloc(sizeof(t_sphere) * 6);
    world.count = 6;
    world.objs[0] = *(t_shape *)&floor;
    world.objs[1] = *(t_shape *)&left_wall;
    world.objs[2] = *(t_shape *)&right_wall;
    world.objs[3] = *(t_shape *)&middle_ball;
    world.objs[4] = *(t_shape *)&right_ball;
    world.objs[5] = *(t_shape *)&left_ball;
    world.light = &(t_point_light) {
        {10, 25, 10, POINT},
        {1, 1, 1, COLOR},
    };

    t_camera camera = create_camera(480, 280, M_PI / 3);
    t_tuple from = (t_tuple){0, 3.5, 3, POINT};
    t_tuple to = (t_tuple){0, 1, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, world);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "three_spheres_in_a_rooms_corner.ppm");
    destroy_canvas(&c);
}
