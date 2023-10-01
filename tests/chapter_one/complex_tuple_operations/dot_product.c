#include "tester.h"

// fun fact: the dot product of two unit vectors is the cosine of the angle between them

#define scenario1                                                                      \
    CYAN "\nGiven a ← vector(1, 2, 3)\n"                                               \
         "And b ← vector(2, 3, 4)\n"                                                   \
         "And dot(a, b, dot_product)\n" 											   \
		 "Then dot_product == 20"	RESET																			
#define scenario2                                                                       \
    CYAN "\nGiven a <-vector(1, 0, 0)\n"                                                \
         "And b <- vector(1, 0, 0)\n"                                                    \
         "And dot(a, b, dot_product) = 1\n" 											 \
		 "Then dot_product == 1" RESET
#define scenario3                                                                        \
    CYAN "\nGiven a <-vector(-1, 0, 0)\n"                                                \
         "And b <- vector(1, 0, 0)\n"                                                    \
         "And dot(a, b, dot_product) = -1\n"                                             \
		 "Then dot_product == -1" RESET
#define scenario4                                                                        \
    CYAN "\nGiven a <-vector(1, 0, 0, 5)\n"                                              \
         "And b <- vector(-1, 0, 0, 1)\n"                                                \
         "Then dot(a, b, dot_product) returns an error" RESET

Test(dot_product, dot_product_of_two_tuples, .description = scenario1) {
	float dot_product;

    dot((t_tuple){1, 2, 3}, (t_tuple){2, 3, 4}, dot_product);
    cr_expect_eq(floats_eq(dot_product, 20.0), TRUE);
}

Test(dot_product, dot_product_of_identical_unit_vectors, .description = scenario2) {
	float dot_product;

    dot((t_tuple){1, 0, 0}, (t_tuple){1, 0, 0}, dot_product);
    cr_expect_eq(floats_eq(dot_product, 1), TRUE);
}

Test(dot_product, dot_product_of_opposite_unit_vectors, .description = scenario3) {
	float dot_product;

    dot((t_tuple){1, 0, 0}, (t_tuple){-1, 0, 0}, dot_product);
    cr_expect_eq(floats_eq(dot_product, -1), TRUE);
}

Test(dot_product, dot_product_of_things_that_are_not_vectors, .description = scenario4) {
    int err = dot((t_tuple){1, 0, 0, 5}, (t_tuple){-1, 0, 0, 1}, (float){0});
    cr_expect_eq(err, -1);
}
