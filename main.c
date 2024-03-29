#include "tests/tester.h"

#define suite_name putting_it_together

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;

typedef struct s_environment {
	t_tuple gravity;
	t_tuple wind;
} t_environment ;

t_projectile tick(t_environment env, t_projectile projectile);
double normalize_y_for_screen(double y, t_canvas canvas);

int main(void) {
    const t_environment e = {
		.gravity = {0, -0.1, 0, VECTOR},
		.wind = {-0.01, 0, 0, VECTOR}
	};
	t_tuple vector = {1, 1.8, 0, VECTOR};
	const t_tuple norm_unit_vector = normalize(vector);
	const t_tuple velo = multiply_tuple_by_scalar(norm_unit_vector, 11.25);
	t_projectile p;

	p = (t_projectile){.position = {0, 100, 0, POINT}, .velocity = {velo.x, velo.y, velo.z, VECTOR}};
	t_canvas canvas = create_canvas(1080, 1920);
    do {
		const int normalized_y = normalize_y_for_screen(p.position.y, canvas);
		write_pixel(&canvas, normalized_y, p.position.x, (const t_four_doubles){1, 0, 0, 3.0});
		printf("y depois: %d\n",(int)p.position.y), printf("x depois: %d\n",(int)p.position.x);
        p = tick(e, p);
    } while (p.position.y >= 0); 
	t_constr str = canvas_to_ppm(&canvas);
	create_ppm_file(str, "projectile.ppm");
}

t_projectile tick(t_environment env, t_projectile projectile) {
	t_projectile res;
	res.position = add_tuples(projectile.position, projectile.velocity);
	res.velocity = add_tuples(projectile.velocity, env.gravity);
	res.velocity = add_tuples(res.velocity, env.wind);
	return (res);
}

double normalize_y_for_screen(double y, t_canvas canvas) {
	return (canvas.height - 1 - y);
}
