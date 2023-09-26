#ifndef TEST_H
#define TEST_H

#include <criterion/criterion.h>
#include "../include/minirt.h"
#include <stdio.h>
#define CYAN "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

inline static void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", a[X], a[Y], a[Z], a[W]);
}

inline static t_bool cr_expect_tuple_eq(const t_tuple result, const t_tuple expected) {
	for (int i = 0; i < 4; i++)
		if (!compare_floats(result[i], expected[i]))
			return (FALSE);
	return (TRUE);
}
#endif
