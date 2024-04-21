#include "minirt.h"

int main() {
	t_shape shape;
	t_world	world;
	
	shape = create_plane();
	mlx_t		*mlx;

	mlx = mlx_init(SIZEW, SIZEH, "TRinim", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	t_matrix transformation_matrix = create_x_rotation_matrix(M_PI / 2);
	print_matrix(transformation_matrix);
	set_transform(&shape, transformation_matrix);
	print_tuple(shape.normal_at(&shape, create_point(0, 0, 0)));
	world.shapes = malloc(sizeof(t_shape) * 1);
	world.shapes[0] = shape;
	world.fixed_count = 1;
	world.moving_idx = 1;
	world.light = (t_point_light){
        {-10, 10, -10, POINT},
        {1, 1, 1, COLOR},
    };

    world.camera = create_camera(SIZEW, SIZEH, M_PI / 3);
    t_tuple from = (t_tuple){0, 1.5, -5, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    forward = subtract_tuples(to, from);
    forward = normalize(forward);
    world.camera.transform = view_transform(from, forward, up);

    render(*get_image_to_render(mlx), world);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
}
