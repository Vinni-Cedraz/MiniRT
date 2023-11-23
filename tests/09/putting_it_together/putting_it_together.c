#include "tester.h"

#include "balls.c"
#include "walls.c"
#include "world.c"
#include "floor.c"

// Test(plane, spheres_on_a_plane_floor) {
//     t_sphere left_ball = create_sphere();
//     t_sphere right_ball = create_sphere();
//     t_sphere middle_ball = create_sphere();
// 	t_plane	 floor = create_plane();
//     t_world  world;
//
// 	// FLOOR
// 	init_tuple((t_tuple){1, 0.9, 0.9, COLOR}, floor.material.color);
// 	floor.material.specular = 0;
// 	set_transform((t_shape *)&floor, create_x_rotation_matrix(2500));
//
// 	// BALLS
//     set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.5, 0.8, 0.1}, &right_ball.material);
// 	set_transform((t_shape *)&right_ball, mult_matrices(
// 				create_translation_matrix((t_tuple){1.10, 1.2, 0.7}),
// 				create_scaling_matrix(0.5, 0.5, 0.5))
// 	);
//     set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.1, 1, 0.1}, &middle_ball.material);
// 	set_transform((t_shape *)&middle_ball, mult_matrices(
// 				create_translation_matrix((t_tuple){0, 1, 0.1}),
// 				create_scaling_matrix(0.7, 0.7, 0.7))
// 	);
// 	set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0.8, 0.1}, &left_ball.material);
// 	set_transform((t_shape *)&left_ball, mult_matrices(
// 				create_translation_matrix((t_tuple){-0.95, 0.89, 0.55}),
// 				create_scaling_matrix(0.33, 0.33, 0.33))
// 	);
//
//     world.objs = malloc(sizeof(t_sphere) * 6);
//     world.count = 6;
//     world.objs[0] = *(t_shape *)&floor;
//     world.objs[1] = *(t_shape *)&middle_ball;
//     world.objs[2] = *(t_shape *)&right_ball;
//     world.objs[3] = *(t_shape *)&left_ball;
//     world.light = &(t_point_light) {
//         {10, 100, 30, POINT},
//         {1, 1, 1, COLOR},
//     };
//
//     t_camera camera = create_camera(480, 240, M_PI / 3);
//     t_tuple from = (t_tuple){0, 3.5, 3, POINT};
//     t_tuple to = (t_tuple){0, 1, 0, POINT};
//     t_tuple up = (t_tuple){0, 1, 0, VECTOR};
//     t_tuple forward;
//
//     subtract_tuples(to, from, forward);
//     normalize(forward, forward);
//     camera.transform = view_transform(from, forward, up);
//
//     t_canvas c = render(camera, world);
//
//     char *str = canvas_to_ppm(&c);
//     create_ppm_file(str, "spheres_floor_plane.ppm");
//     destroy_canvas(&c);
// }

Test(plane, spheres_floor_wall_planes) {
	t_plane floor = create_plane();
    t_world world;
	t_plane walls[] = {
		(t_plane)create_plane(),
		(t_plane)create_plane(),
		(t_plane)create_plane(),
		(t_plane)create_plane(),
		(t_plane)create_plane(),
		(t_plane)create_plane(),
	};
    t_sphere balls[] = {
		create_sphere(),
		create_sphere(),
		create_sphere()
	};

	init_floor((t_shape *)&floor);
	init_balls(balls);
	init_walls(walls);
	init_world(&world, (t_shape *)&floor, balls, walls);

    t_camera camera = create_camera(480, 240, M_PI / 3);
    t_tuple from = (t_tuple){0, 50, 0, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 0, -1, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, world);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "spheres_floor_wall_planes.ppm");
    destroy_canvas(&c);
}
