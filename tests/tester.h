#ifndef TEST_H
#define TEST_H

#include "../include/minirt.h"
#include <criterion/criterion.h>
#include <stdio.h>
#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"

static inline t_bool cr_expect_tuples_eq(const t_tuple result, const t_tuple expected) {

    cr_expect(doubles_eq(result.x, expected.x), RED ".x value of the tuples are different" RESET);
    if (!doubles_eq(result.x, expected.x))
        return (FALSE);
    cr_expect(doubles_eq(result.y, expected.y), RED ".y value of the tuples are different" RESET);
    if (!doubles_eq(result.y, expected.y))
        return (FALSE);
    cr_expect(doubles_eq(result.z, expected.z), RED ".z value of the tuples are different" RESET);
    if (!doubles_eq(result.z, expected.z))
        return (FALSE);
    cr_expect(doubles_eq(result.w, expected.w), RED ".w value of the tuples are different" RESET);
    if (!doubles_eq(result.w, expected.w))
        return (FALSE);
    return (TRUE);
}

static inline void set_all_pixels_to_one_color(const t_canvas *c, t_tuple color) {
    for (int y = 0; y < c->height; y++)
        for (int x = 0; x < c->width; x++)
            write_pixel((t_canvas *)c, y, x, color);
}

static inline void create_ppm_file(t_constr ppm_string, t_constr filename) {
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, ppm_string, strlen(ppm_string));
    close(fd);
}

static inline int invert_axis(int size, double axis) { return ((int)size - axis); }

#endif
