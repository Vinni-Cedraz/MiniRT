#ifndef TEST_H
#define TEST_H

#include <criterion/criterion.h>
#include "minirt.h"
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

static inline void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", a[X], a[Y], a[Z], a[W]);
}

static inline void print_4x4matrix(const t_matrix a)
{
	print_tuple(a.row_1);
	print_tuple(a.row_2);
	print_tuple(a.row_3);
	print_tuple(a.row_4);
}

static inline t_bool cr_expect_tuples_eq(const t_tuple result, const t_tuple expected) { for (int i = 0; i < 4; i++) {
		cr_expect(floats_eq(result[i], expected[i]));
		if (!floats_eq(result[i], expected[i]))
			return (1);
	}
	return (0);
}

static inline void set_all_pixels_to_one_color(const t_canvas *c, t_tuple color) {
    for (int y = 0; y < c->height; y++)
        for (int x = 0; x < c->width; x++)
            write_pixel((t_canvas *)c, y, x, color);
}

static inline void create_ppm_file(t_constr ppm_string, t_constr filename) {
	int fd = open(filename,  O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	write(fd, ppm_string, strlen(ppm_string));
	close(fd);
}

static inline t_bool	cr_expect_matrices_eq(t_matrix a, t_matrix b)
{
	int	res;

	res = cr_expect_tuples_eq(a.row_1, b.row_1);
	res = cr_expect_tuples_eq(a.row_2, b.row_2);
	res = cr_expect_tuples_eq(a.row_3, b.row_3);
	res = cr_expect_tuples_eq(a.row_4, b.row_4);
	return (!res);
}

static inline int invert_axis(int size, float axis)
{
	return ((int)size - axis);
}

static inline void create_a_vector(float x, float y, float z, t_tuple res)
{
	res[X] = x;
	res[Y] = y;
	res[Z] = z;
	res[W] = VECTOR;
}
static inline void create_a_point(float x, float y, float z, t_tuple res)
{
	res[X] = x;
	res[Y] = y;
	res[Z] = z;
	res[W] = POINT;
}

// #define scenario1 CYAN \
// "\nGiven point(0, 0, 0, POINT)\n"\
// "And canvas(500, 500)\n" \
// "And p ← translate_coordinate(point, canvas)\n " \
// "Then p = point(250, 250, 0, POINT)\n"RESET
//

void quick_render(t_world *w) {

    t_camera camera = create_camera(480, 280, M_PI / 4);
    t_tuple from = (t_tuple){-1.5, -15, 10, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 0, 1, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, *w);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "main.ppm");
    destroy_canvas(&c);
    free(str);
    free(w->objs);
}

#endif
