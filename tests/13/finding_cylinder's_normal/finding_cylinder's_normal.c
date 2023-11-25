#include "tester.h"
// Scenario Outline : Normal vector on a cylinder
#define scenario1 CYAN                            \
"\nGiven cyl ← cylinder()\n"                      \
"When n ← cylinder_normal_at(cyl, point(1, 0, 0)\n"  \
"Then n = vector(1, 0, 0) \n"                             \

Test(finding_normal, point_1_0_0, .description = scenario1) {
	t_cylinder		cyl = create_cylinder();
	const t_tuple 	normal;
	const t_tuple 	point = {1, 0, 0, POINT};
	const t_tuple 	expected_normal = {1, 0, 0, VECTOR};
	cylinder_normal_at(&cyl, point, normal);
	cr_expect_tuples_eq(expected_normal, normal);
}

// Scenario Outline : Normal vector on a cylinder
#define scenario2 CYAN                            \
"\nGiven cyl ← cylinder()\n"                      \
"When n ← cylinder_normal_at(cyl, point(0, 5, -1)\n"  \
"Then n = vector(0, 0, -1) \n"                             \

Test(finding_normal, point_0_5_1, .description = scenario2) {
	t_cylinder		cyl = create_cylinder();
	const t_tuple 	normal;
	const t_tuple 	point = {0, 5, -1, POINT};
	const t_tuple 	expected_normal = {0, 0, -1, VECTOR};
	cylinder_normal_at(&cyl, point, normal);
	cr_expect_tuples_eq(expected_normal, normal);
}

// Scenario Outline : Normal vector on a cylinder
#define scenario3 CYAN                            \
"\nGiven cyl ← cylinder()\n"                      \
"When n ← cylinder_normal_at(cyl, point(0, -2, 1)\n"  \
"Then n = vector(0, 0, 1) \n"                             \

Test(finding_normal, point_0_2_1, .description = scenario3) {
	t_cylinder		cyl = create_cylinder();
	const t_tuple 	normal;
	const t_tuple 	point = {0, -2, 1, POINT};
	const t_tuple 	expected_normal = {0, 0, 1, VECTOR};
	cylinder_normal_at(&cyl, point, normal);
	cr_expect_tuples_eq(expected_normal, normal);
}

#define scenario4 CYAN 							  \
"\nGiven cyl ← cylinder()\n"                      \
"When n ← cylinder_normal_at(cyl, point(-1, 1, 0)\n"  \
"Then n = vector(-1, 0, 0) \n"                             \

Test(finding_normal, point_1_1_0, .description = scenario3) {
	t_cylinder		cyl = create_cylinder();
	const t_tuple 	normal;
	const t_tuple 	point = {-1, 1, 0, POINT};
	const t_tuple 	expected_normal = {-1, 0, 0, VECTOR};
	cylinder_normal_at(&cyl, point, normal);
	cr_expect_tuples_eq(expected_normal, normal);
}
