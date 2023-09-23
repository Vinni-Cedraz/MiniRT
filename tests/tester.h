#ifndef TEST_H
#define TEST_H

// #include  "../include/minirt.h"
#include "../include/minirt.h"
#include <stdio.h>
#define CYAN "\033[36m"
#define RESET "\033[0m"
#include <criterion/criterion.h>

inline static void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", a[X], a[Y], a[Z], a[W]);
}

#endif
