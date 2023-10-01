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
    t_canvas c = create_canvas(550, 900);

    while ((p.position[Y] >= 0) && (p.position[Y] < c.height) &&
           (p.position[X] < c.width)) {
        y = (int)c.height - p.position[Y];
        x = (int)p.position[X];
        write_pixel(&c, y, x, (t_tuple){1, 0, 0, COLOR});
        p = tick(e, p);
    }
    t_constr ppm_string = canvas_to_ppm(&c);
    create_ppm_file(ppm_string, "$HOME/MiniRT/tests/chapter_two/putting_it_together/projectile_chapter_two.ppm");
}
