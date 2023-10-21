#include "minirt.h"
#include "tester.h"
#define SQRT_OF_2 1.41421

// Scenario : Reflecting a vector approaching at 45°
#define scenario1                                                                      \
    CYAN "\nGiven v ← vector(1, -1, 0)\n"                                              \
         "And normal ← vector(0, 1, 0)\n"                                              \
         "When r ← reflect(v, n)\n"                                                    \
         "Then r = vector(1, 1, 0)\n"

Test(reflecting, approaching_at_45, .description = scenario1) {
    const t_tuple v = {1, -1, 0, VECTOR};
    const t_tuple n = {0, -1, 0, VECTOR};
    t_tuple res;

    reflect(v, n, res);
    cr_expect_tuple_eq(res, (t_tuple){1, 1, 0});
}

// Scenario : Reflecting a vector off a slanted surface
#define scenario2                                                                      \
    CYAN "Given v ← vector(0, -1, 0)\n"                                                \
         "And normal ← vector(√2/2, √2/2, 0)\n"                                        \
         "When r ← reflect(v, n)\n"                                                    \
         "Then r = vector(1, 0, 0)\n"

Test(reflecting, reflecting_a_vector, .description = scenario1) {
    const t_tuple v = {0, -1, 0, VECTOR};
    const t_tuple normal = {(SQRT_OF_2/2), (SQRT_OF_2/2), 0, VECTOR};
    t_tuple res;

    reflect(v, normal, res);
    cr_expect_tuple_eq(res, (t_tuple){1, 0, 0, VECTOR});
}
