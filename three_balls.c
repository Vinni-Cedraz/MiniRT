#include "minirt.h"

int main() {
    t_shape 	left_ball = create_sphere();
    t_shape 	right_ball = create_sphere();
    t_shape 	middle_ball = create_sphere();
    t_shape 	floor = create_sphere();
    t_shape 	left_wall = create_sphere();
    t_shape 	right_wall = create_sphere();
    t_world		world;
    t_matrix 	translation = create_translation_matrix((t_tuple){0, 0, 5, POINT});
    t_matrix 	scaling = create_scaling_matrix(10, 0.01, 10);
	mlx_t		*mlx;

	mlx = mlx_init(SIZEW, SIZEH, "TRinim", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
    // FLOOR
    floor.material = create_material();
    floor.material.color = create_tuple(1, 0.9, 0.9, COLOR);
    floor.material.specular = 0;
    set_transform((t_shape *)&floor, scaling);

    // BALLS
	

	middle_ball.material.color = create_tuple(0.1, 1, 0.5, COLOR);
	middle_ball.material.diffuse = 0.7;
	middle_ball.material.specular = 0.3;
    set_transform((t_shape *)&middle_ball, create_translation_matrix((t_tuple){-0.5, 1, 0.5, POINT}));

	right_ball.material.color = (t_tuple){0.5, 1, 0.1, COLOR};
	right_ball.material.specular = 0.3;
	right_ball.material.diffuse = 0.7;
    set_transform((t_shape *)&right_ball, mult_matrices(create_translation_matrix((t_tuple){1, 0.5, -0.75, POINT}),
                                                        create_scaling_matrix(0.5, 0.5, 0.5)));

	left_ball.material.color = create_tuple(1, 0.8, 0.1, COLOR);
	left_ball.material.diffuse = 0.7;
	left_ball.material.specular = 0.3;
    set_transform((t_shape *)&left_ball, mult_matrices(create_translation_matrix((t_tuple){-1.5, 0.33, -0.75, POINT}),
                                                       create_scaling_matrix(0.33, 0.33, 0.33)));

    // LEFT_WALL
    t_matrix y_rotation = create_y_rotation_matrix(-M_PI / 4);
    t_matrix x_rotation = create_x_rotation_matrix(M_PI / 2);
    set_transform((t_shape *)&left_wall,
                  chain_transformations((t_matrix []){scaling, x_rotation, y_rotation, translation, create_identity_matrix()}));
    left_wall.material = floor.material;

    // RIGHT_WALL
    y_rotation = create_y_rotation_matrix(M_PI / 4);
    set_transform((t_shape *)&right_wall,
                  chain_transformations((t_matrix []){scaling, x_rotation, y_rotation, translation, create_identity_matrix()}));
    right_wall.material = floor.material;

    world.shapes = malloc(sizeof(t_shape) * 6);
    world.fixed_count = 6;
    world.shapes[0] = *(t_shape *)&floor;
    world.shapes[1] = *(t_shape *)&left_wall;
    world.shapes[2] = *(t_shape *)&right_wall;
    world.shapes[3] = *(t_shape *)&middle_ball;
    world.shapes[4] = *(t_shape *)&right_ball;
    world.shapes[5] = *(t_shape *)&left_ball;

    world.light = (t_point_light){
        {-10, 10, -10, POINT},
        {1, 1, 1, COLOR},
    };

    world.camera = create_camera(SIZEW, SIZEH, M_PI / 3);
    t_tuple from = (t_tuple){0, 200, -1500, POINT};
    t_tuple to = (t_tuple){0, 1, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    forward = subtract_tuples(to, from);
    forward = normalize(forward);
    world.camera.transform = view_transform(from, forward, up);

    render(*get_image_to_render(mlx), world);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
}
