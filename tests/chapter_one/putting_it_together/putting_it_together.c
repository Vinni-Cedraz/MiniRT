#include "tester.h"

#define suite_name putting_it_together

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;

typedef struct s_environment {
    t_tuple gravity;
    t_tuple wind;
} t_environment;

// returns a new projectile that represents the given projectile after one unit of time (one tick) has passed
t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile res;

    add_tuples(projectile.position, projectile.velocity, res.position);
    add_tuples(projectile.velocity, env.gravity, res.velocity);
    add_tuples(res.velocity, env.wind, res.velocity);
    return (res);
}

// projectile starts one unit above the origin.
// velocity is normalized to 1 unit/tick.
// p ← projectile(point(0, 1, 0), normalize(vector(1, 1, 0)))
// gravity -0.1 unit/tick, and wind is -0.01 unit/tick.
// e ← environmenThen, run tick repeatedly until the projectile’s y position is less
// than or equal to 0. Report the projectile’s position after each
// tick, and the number of ticks it takes for the projectile to hit the
// ground.t(vector(0, -0.1, 0), vector(-0.01, 0, 0))
Test(suite_name, projectile_is_falling) {
	t_projectile p = (t_projectile){.position = {}, .velocity = {}};
	t_environment e = (t_environment){.gravity = {}, .wind = {}};

	printf(CYAN"Projectile position: "RESET);
	print_tuple(p.position);
}
