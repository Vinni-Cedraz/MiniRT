#include "tester.h"

#define suite_name putting_it_together

t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile p;

    add_tuples(projectile.position, projectile.velocity, p.position);
    add_tuples(projectile.velocity, env.gravity, p.velocity);
    add_tuples(p.velocity, env.wind, p.velocity);
    return (p);
}

Test(suite_name, projectile_goes_up_and_down) {
	t_tuple vec = {1, 1.8, 0, VECTOR};
	t_projectile p = {.position = {0, 1, 0}};
	int y, x;

	normalize(vec, p.velocity);
	multiply_tuple_by_scalar(p.velocity, 11.25, p.velocity);
    const t_environment e = {.gravity = {0, -0.1, 0}, .wind = {-0.01, 0, 0}};
	t_canvas c = create_canvas(20, 10);
    do {
		y = (int)c.height - p.position[Y];
		x = (int)p.position[X];
		write_pixel(&c, y, x, (t_tuple){1, 0, 0, COLOR});
		// cr_expect_tuple_eq(c.pixels[y][x], (t_tuple){1, 0, 0, COLOR});
		printf("x: %d, y: %d\n", x, y);
        p = tick(e, p);
    } while ((p.position[Y] >= 0) && p.position[X] < c.width);

	t_constr ppm_string = canvas_to_ppm(&c);
	printf("%s\n", ppm_string);
}
