#include "tester.h"

void init_balls(t_sphere balls[]) {
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.5, 0.8, 0.1}, &balls[0].material);
	set_transform((t_shape *)&balls[0], mult_matrices(
				create_translation_matrix((t_tuple){1.10, 1.2, 0.7}),
				create_scaling_matrix(0.5, 0.5, 0.5))
	);
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){0.1, 1, 0.1}, &balls[1].material);
	set_transform((t_shape *)&balls[1], mult_matrices(
				create_translation_matrix((t_tuple){0, 1, 0.1}),
				create_scaling_matrix(0.7, 0.7, 0.7))
	);
	set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0.8, 0.1}, &balls[2].material);
	set_transform((t_shape *)&balls[2], mult_matrices(
				create_translation_matrix((t_tuple){-0.95, 0.89, 0.55}),
				create_scaling_matrix(0.33, 0.33, 0.33))
	);
}
