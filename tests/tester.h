#ifndef TEST_H
#define TEST_H

// #include  "../include/minirt.h"
#include "../include/minirt.h"
#include <criterion/criterion.h>
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define VECTOR 0
#define POINT 1

inline static void	print_tuple(t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", a[X], a[Y], a[Z], a[W]);
}

#endif
