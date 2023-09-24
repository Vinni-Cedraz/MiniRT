#include "../../tester.h"

#define suite_name putting_it_together

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;
typedef struct s_environment {
    t_tuple gravity;
    t_tuple wind;
} t_environment;

t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile res;

    add_tuples(projectile.position, projectile.velocity, res.position);
    add_tuples(projectile.velocity, env.gravity, res.velocity);
    add_tuples(res.velocity, env.wind, res.velocity);
    return (res);
}

Test(suite_name, projectile_goes_up_and_down) {
    const t_environment e = {.gravity = {0, -0.1, 0}, .wind = {-0.01, 0, 0}};
    t_projectile p = {.position = {0, 1, 0}, .velocity = {1, 1, 0}};

    do {
        printf(CYAN "Projectile position: " RESET);
        print_tuple(p.position);
        p = tick(e, p);
    } while ((p.position[Y] >= 0)); 
    printf(CYAN "Projectile position: " RESET);
    print_tuple(p.position);
}
