#include "tester.h"

#define suite_name putting_it_together

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;

t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile res;

    res.position = add_tuples(projectile.position, projectile.velocity);
    res.velocity = add_tuples(projectile.velocity, env.gravity);
    res.velocity = add_tuples(res.velocity, env.wind);
    return (res);
}

Test(suite_name, projectile_goes_up_and_down) {
    const t_environment e = {.gravity = {0, -0.1, 0}, .wind = {-0.01, 0, 0}};
	t_tuple vector = {1,1.8, 0, VECTOR};
	const t_tuple norm_unit_vector = normalize(vector);
	const t_tuple velo = multiply_tuple_by_scalar(norm_unit_vector, 11.25);
	t_projectile p;

	p = (t_projectile){.position = {0, 1, 0, POINT}, .velocity = {velo.x, velo.y, velo.z, VECTOR}};
	t_canvas canvas = create_canvas(900, 550);
    do {
		write_pixel(&canvas, p.position.y, p.position.x, (const t_four_doubles){1, 0, 0, 3.0});
        p = tick(e, p);
    } while ((p.position.y >= 0)); 
	t_constr str = canvas_to_ppm(&canvas);
	create_ppm_file(str, "projectile.ppm");
}
