#include "tester.h"

#define suite_name putting_it_together

t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile res;

    add_tuples(projectile.position, projectile.velocity, res.position);
    add_tuples(projectile.velocity, env.gravity, res.velocity);
    add_tuples(res.velocity, env.wind, res.velocity);
    return (res);
}

Test(suite_name, projectile_goes_up_and_down) {
    const t_environment e = {.gravity = {0, -0.1, 0}, .wind = {-0.01, 0, 0}};
	t_tuple vector = {1,1.8, 0, VECTOR};
	t_projectile p;
	t_tuple unit_vector;
	t_tuple velo;

	normalize(vector, unit_vector);
	multiply_tuple_by_scalar(unit_vector, 11.25, velo);
    p = (t_projectile){.position = {0, 1, 0, POINT}, .velocity = {velo[0], velo[1], velo[2], VECTOR}};
	t_canvas canvas = create_canvas(900, 550);
    do {
		write_pixel(&canvas, p.position[Y], p.position[X], (t_tuple){1,0,0});
        p = tick(e, p);
    } while ((p.position[Y] >= 0)); 
	t_constr str = canvas_to_ppm(&canvas);
	create_ppm_file(str, "projectile.ppm");
}
