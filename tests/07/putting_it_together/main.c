#include "../../../include/minirt.h"
#include "../../tester.h"

int main (void)
{
	t_sphere	floor;
	t_sphere	left_wall;
	t_sphere	right_wall;
	t_sphere	middle_sphere;
	t_sphere 	right_sphere;
	t_sphere 	left_sphere;

	floor = create_sphere();
	floor._t = create_scaling_matrix(10, 0.01, 10);
	floor.material = create_material();
	init_tuple((t_tuple){1, 0.9, 0.9, COLOR}, floor.material.color);
	floor.material.specular = 0;
	left_wall = create_sphere();

	t_matrix translation = create_translation_matrix((t_tuple){0, 0, 5, POINT});
 	t_matrix y_rotation = create_y_rotation_matrix(-M_PI / 4);
 	t_matrix x_rotation = create_x_rotation_matrix(M_PI / 2);
 	t_matrix scaling = create_scaling_matrix(10, 0.01, 10);

	// WALLS
	left_wall._t = chain_transformations((t_matrix *[]){&translation, &y_rotation, &x_rotation, &scaling, NULL});
	left_wall.material = floor.material;
	right_wall = create_sphere();

 	y_rotation = create_y_rotation_matrix(M_PI / 4);
	right_wall._t = chain_transformations((t_matrix *[]){&translation, &y_rotation, &x_rotation, &scaling, NULL});
	right_wall.material = floor.material;

	//  MIDDLE SPHERE
	middle_sphere = create_sphere();
	middle_sphere._t = create_translation_matrix((t_tuple){-0.5, 1, 0.5, POINT});
	middle_sphere.material = create_material();
	set_material((t_tuple){-1, 0.7, 0.3, -1}, (t_tuple){0.1, 1, 0.5, COLOR}, &middle_sphere.material);

	// RIGHT SPHERE
	right_sphere = create_sphere();
	t_matrix result;
	right_sphere._t = mult_matrices(
			create_translation_matrix((t_tuple){1.5, 0.5, -0.5}),
			create_scaling_matrix(0.5, 0.5, 0.5)
	);
	right_sphere.material = create_material();
	set_material((t_tuple){-1, 0.7, 0.3, -1}, (t_tuple){0.5, 1, 0.1, COLOR}, &right_sphere.material);

	// LEFT SPHERE
	left_sphere = create_sphere();
	left_sphere._t = mult_matrices(
			create_translation_matrix((t_tuple){-1.5, 0.33, -0.75}),
			create_scaling_matrix(0.33, 0.33, 0.33)
	);
	left_sphere.material = create_material();
	set_material((t_tuple){-1, 0.7, 0.3, -1}, (t_tuple){1, 0.8, 0.1, COLOR}, &left_sphere.material);

	t_world world;

	world.count = 6;
	world.objs = malloc(sizeof(t_sphere) * world.count);
	world.objs[0] = floor;
	world.objs[1] = left_wall;
	world.objs[2] = right_wall;
	world.objs[3] = left_sphere;
	world.objs[4] = middle_sphere;
	world.objs[5] = right_sphere;
	world.light = &(t_point_light){
		{-10, 10, -10, POINT},
		{1, 1, 1, COLOR},
	};

	t_camera camera = create_camera(100, 50, M_PI / 3);
	t_tuple from = (t_tuple){0, 1.5, -5, POINT};
	t_tuple to = (t_tuple){0, 1, 0, POINT};
	t_tuple up = (t_tuple){0, 1, 0, VECTOR};
	t_tuple forward;

	subtract_tuples(to, from, forward);
	normalize(forward, forward);
	camera.transform = view_transform(from, forward, up);

	t_canvas canvas = render(camera, world);

    t_constr *str = canvas_to_ppm(&canvas);
    create_ppm_file(str);
    destroy_canvas(&canvas);
	free(world.objs);
}
