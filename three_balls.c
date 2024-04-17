#include "minirt.h"

int main() {
    t_sphere 	left_ball = create_sphere();
    t_sphere 	right_ball = create_sphere();
    t_sphere 	middle_ball = create_sphere();
    t_sphere 	floor = create_sphere();
    t_sphere 	left_wall = create_sphere();
    t_sphere 	right_wall = create_sphere();
    t_world		world;
    t_matrix 	translation = create_translation_matrix((t_tuple){0, 0, -1, POINT});
    t_matrix 	scaling = create_scaling_matrix(10, 0.01, 10);
	mlx_t		*mlx;

	mlx = mlx_init(SIZEH, SIZEW, "TRinim", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
    // FLOOR
    floor.material = create_material();
    floor.material.color = create_tuple(1, 0, 0, COLOR);
    floor.material.specular = 0;
    set_transform((t_sphere *)&floor, create_scaling_matrix(10, 0.01, 10));

    // BALLS
	

    set_transform((t_sphere *)&right_ball, mult_matrices(create_translation_matrix((t_tuple){1.15, 0.7, 0.5, POINT}),
                                                        create_scaling_matrix(0.5, 0.5, 0.5)));
	right_ball.material.color = (t_tuple){0, 0, 1, COLOR};

    set_transform((t_sphere *)&middle_ball, mult_matrices(create_translation_matrix((t_tuple){0, 0.8, 0.1, POINT}),
                                                         create_scaling_matrix(0.7, 0.7, 0.7)));

    set_transform((t_sphere *)&left_ball, mult_matrices(create_translation_matrix((t_tuple){-0.95, 0.33, 0.4, POINT}),
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

    world.objs = malloc(sizeof(t_sphere) * 6);
    world.count = 6;
    world.objs[0] = *(t_sphere *)&floor;
    world.objs[1] = *(t_sphere *)&left_wall;
    world.objs[2] = *(t_sphere *)&right_wall;
    world.objs[3] = *(t_sphere *)&middle_ball;
    world.objs[4] = *(t_sphere *)&right_ball;
    world.objs[5] = *(t_sphere *)&left_ball;

    world.light = (t_point_light){
        {10, 25, 10, POINT},
        {1, 1, 1, COLOR},
    };

    t_camera camera = create_camera(SIZEH, SIZEW, M_PI / 3);
    t_tuple from = (t_tuple){0, 3.5, 3, POINT};
    t_tuple to = (t_tuple){0, 1, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    forward = subtract_tuples(to, from);
    forward = normalize(forward);
    camera.transform = view_transform(from, forward, up);

    render(*get_image_to_render(mlx), camera, world);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
}
