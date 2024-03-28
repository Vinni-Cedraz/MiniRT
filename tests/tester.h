#ifndef TEST_H
#define TEST_H

#include "minirt.h"
#include <criterion/criterion.h>
#include <stdio.h>
#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;

typedef struct s_environment {
    t_tuple gravity;
    t_tuple wind;
} t_environment;

static inline t_bool cr_expect_tuples_eq(const t_tuple result, const t_tuple expected) {

    cr_expect(doubles_eq(result.x, expected.x));
    if (!doubles_eq(result.x, expected.x))
        return (FALSE);
    cr_expect(doubles_eq(result.y, expected.y));
	if (!doubles_eq(result.y, expected.y))
		return (FALSE);
    cr_expect(doubles_eq(result.z, expected.z));
	if (!doubles_eq(result.z, expected.z))
		return (FALSE);
    cr_expect(doubles_eq(result.w, expected.w));
	if (!doubles_eq(result.w, expected.w))
		return (FALSE);
    return (TRUE);
}

static inline void set_all_pixels_to_one_color(const t_canvas *c, t_tuple color) {
    for (int y = 0; y < c->height; y++)
        for (int x = 0; x < c->width; x++)
            write_pixel((t_canvas *)c, y, x, (t_four_doubles){color.x, color.y, color.z, color.w});
}

static inline void create_ppm_file(t_constr ppm_string, t_constr filename) {
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, ppm_string, strlen(ppm_string));
    close(fd);
}

static inline t_bool cr_expect_matrices_eq(t_matrix a, t_matrix b) {
    int res;

    res = cr_expect_tuples_eq(a.row_1, b.row_1);
    res = cr_expect_tuples_eq(a.row_2, b.row_2);
    res = cr_expect_tuples_eq(a.row_3, b.row_3);
    res = cr_expect_tuples_eq(a.row_4, b.row_4);
    return (!res);
}

static inline int invert_axis(int size, double axis) { return ((int)size - axis); }

void quick_render(t_world *w, const t_tuple from) {

    t_camera camera = create_camera(800, 600, M_PI / 4);
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    const t_tuple forward = subtract_tuples(to, from);

    const t_tuple normalized_forward = normalize(forward);
    camera.transform = view_transform(from, normalized_forward, up);

    t_canvas c = render(camera, *w);
    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "main.ppm");
    destroy_canvas(&c);
    free(str);
    free(w->objs);
}

void create_test_world(t_world *world, const t_tuple from, int num_shapes, ...) {
    va_list shapes;
    va_start(shapes, num_shapes);

    world->objs = malloc(sizeof(t_shape) * num_shapes);
    world->count = num_shapes;
    for (int i = 0; i < num_shapes; i++) {
        t_shape shape = va_arg(shapes, t_shape);
        world->objs[i] = *(t_shape *)&shape;
    }
    quick_render(world, from);
    va_end(shapes);
}

#endif
