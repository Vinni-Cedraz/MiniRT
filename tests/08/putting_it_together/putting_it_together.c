#include "../../tester.h"

Test(putting, it_together) {
    t_sphere left_ball = create_sphere();
    t_sphere right_ball = create_sphere();
    t_sphere middle_ball = create_sphere();
    t_sphere floor = create_sphere();
    t_sphere left_wall = create_sphere();
    t_sphere right_wall = create_sphere();
	t_cylinder cyl = create_cylinder();
	t_cylinder right_cyl = create_cylinder();
    t_world world;
	mlx_t	*mlx;

	mlx = mlx_init(SIZEW, SIZEH, "putting_it_together", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
    t_matrix translation = create_translation_matrix((t_tuple){0, 0, -1, POINT});
    t_matrix scaling = create_scaling_matrix(10, 0.01, 10);
	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, -2, 1);

	right_cyl.closed = TRUE;
	set_cyl_min_max(&right_cyl, -1, 0.5);
	set_transform((t_sphere *)&right_cyl, mult_matrices(create_translation_matrix((t_tuple){1.85, 0.7, 0.5, POINT}),
                                                        create_scaling_matrix(0.65, 0.65, 0.65)));
	init_tuple((t_tuple){0, 0, 1, COLOR}, right_cyl.material.color);

    // FLOOR
    floor.material = create_material();
    init_tuple((t_tuple){1, 0.9, 0.9, COLOR}, floor.material.color);
    floor.material.specular = 0;
    set_transform((t_sphere *)&floor, create_scaling_matrix(10, 0.01, 10));

    // BALLS
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.5, 1, 0.1, POINT}, &right_ball.material);
    set_transform((t_sphere *)&right_ball, mult_matrices(create_translation_matrix((t_tuple){1.85, 0.7, 0.5, POINT}),
                                                        create_scaling_matrix(0.5, 0.5, 0.5)));

    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.1, 1, 0.1, POINT}, &middle_ball.material);
    set_transform((t_sphere *)&middle_ball, mult_matrices(create_translation_matrix((t_tuple){0, 0.8, 0, POINT}),
                                                         create_scaling_matrix(0.7, 0.7, 0.7)));

    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0.8, 0.1, POINT}, &left_ball.material);
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.5, 1, 0.1, COLOR}, &right_ball.material);
    set_transform((t_sphere *)&right_ball, mult_matrices(create_translation_matrix((t_tuple){1.85, 0.7, 0.5, POINT}),
                                                        create_scaling_matrix(0.5, 0.5, 0.5)));

    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.1, 1, 0.1, COLOR}, &middle_ball.material);
    set_transform((t_sphere *)&middle_ball, mult_matrices(create_translation_matrix((t_tuple){0, 0.8, 0, POINT}),
                                                         create_scaling_matrix(0.7, 0.7, 0.7)));

    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0.8, 0.1, COLOR}, &left_ball.material);
    set_transform((t_sphere *)&left_ball, mult_matrices(create_translation_matrix((t_tuple){-1.95, 0.33, 0.4, POINT}),
                                                       create_scaling_matrix(0.33, 0.33, 0.33)));

    // LEFT_WALL
    t_matrix y_rotation = create_y_rotation_matrix(-M_PI / 4);
    t_matrix x_rotation = create_x_rotation_matrix(M_PI / 2);
    set_transform((t_sphere *)&left_wall,
                  chain_transformations((t_matrix []){scaling, x_rotation, y_rotation, translation, create_identity_matrix()}));
    left_wall.material = floor.material;

    // RIGHT_WALL
    y_rotation = create_y_rotation_matrix(M_PI / 4);
    set_transform((t_sphere *)&right_wall,
                  chain_transformations((t_matrix []){scaling, x_rotation, y_rotation, translation, create_identity_matrix()}));
    right_wall.material = floor.material;

    world.count = 8;
    world.objs = malloc(sizeof(t_sphere) * world.count);
    world.objs[0] = *(t_sphere *)&floor;
    world.objs[1] = *(t_sphere *)&left_wall;
    world.objs[2] = *(t_sphere *)&right_wall;
    world.objs[3] = *(t_sphere *)&middle_ball;
    world.objs[4] = *(t_sphere *)&right_ball;
    world.objs[5] = *(t_sphere *)&left_ball;
    world.objs[6] = *(t_sphere *)&cyl;
    world.objs[7] = *(t_sphere *)&right_cyl;

    world.light = (t_point_light){
        {0, 5, 120, POINT},
        {1, 1, 1, COLOR},
    };

    t_camera camera = create_camera(1920/2, 1080/2, M_PI / 3);
    t_tuple from = (t_tuple){0.5, 4.5, 5, POINT};
    t_tuple to = (t_tuple){0, 1, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    forward = subtract_tuples(to, from);
    forward = normalize(forward);
    camera.transform = view_transform(from, forward, up);

    render(*get_image_to_render(mlx), world);
	free(world.objs);
}
