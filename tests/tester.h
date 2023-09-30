#ifndef TEST_H
#define TEST_H

#include <criterion/criterion.h>
#include "minirt.h"
#include <stdio.h>
#define CYAN "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
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

static inline t_bool cr_expect_tuple_eq(const t_tuple result, const t_tuple expected) {
	for (int i = 0; i < 4; i++)
		if (!compare_floats(result[i], expected[i]))
			return (FALSE);
	return (TRUE);
}

static inline void set_all_pixels_to_one_color(const t_canvas *c, t_tuple color) {
    for (int y = 0; y < c->height; y++)
        for (int x = 0; x < c->width; x++)
            write_pixel((t_canvas *)c, y, x, color);
}


static inline void create_ppm_file(t_constr ppm_string, const char filename[]) {
	char CMD[STR_LIMIT];
	sprintf(CMD, "echo '%s' > %s", ppm_string, filename);
	system(CMD);
}

#endif
