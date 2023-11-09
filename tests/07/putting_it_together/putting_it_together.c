#include "minirt.h"
#include "tester.h"

Test(putting_it_together, three_spheres)
{
	t_sphere	floor;
	t_sphere	left_wall;
	t_sphere	right_wall;
	t_sphere	middle_wall;

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
	t_matrix identity = create_identity_matrix();
	NULL;

	left_wall._t = chain_transformations((t_matrix *[]){&translation, &y_rotation, &x_rotation, &scaling, &identity});
	left_wall.material = floor.material;
	right_wall = create_sphere();

 	y_rotation = create_y_rotation_matrix(M_PI / 4);
	right_wall._t = chain_transformations((t_matrix *[]){&translation, &y_rotation, &x_rotation, &scaling, &identity});
	right_wall.material = floor.material;

	middle_wall = create_sphere();
	middle_wall._t = create_translation_matrix((t_tuple){-0.5, 1, 0.5, POINT});
	middle_wall.material = create_material();
	init_tuple((t_tuple){0.1, 1, 0.5, COLOR}, middle_wall.material.color);
	middle_wall.material.diffuse = 0.7;
	middle_wall.material.specular = 0.3;
}
