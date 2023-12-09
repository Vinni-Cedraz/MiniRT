#include "tester.h"

// Scenario: The default closed value for a cylinder
#define scenario1 CYAN \
"\nGiven cyl ← cylinder()\n" \
"Then cyl.closed = false"RESET

Test(capped_cylinders, open_closed, .description = scenario1)
{
	t_cylinder cyl = create_cylinder();
	cr_assert_eq(cyl.closed, FALSE);
}

// Scenario Outline: Intersecting the caps of a closed cylinder
#define scenario2 CYAN \
"\nGiven cyl ← cylinder()\n"                    \
"And cyl.minimum ← 1\n"                    \
"And cyl.maximum ← 2\n"                    \
"And cyl.closed ← true\n"                    \
"And direction ← normalize(<direction>)\n"                    \
"And r ← ray(<point>, direction)\n"                    \
"When xs ← local_intersect(cyl, r)\n"                    \
"Then xs.count = <count>\n"                    \

// Examples:
// | x | point            | direction        | count |
// | 1 | point(0, 3, 0)   | vector(0, -1, 0) | 2 
// | 2 | point(0, 3, -2)  | vector(0, -1, 2) | 2
// | 3 | point(0, 4, -2)  | vector(0, -1, 1) | 2
// | 4 | point(0, 0, -2)  | vector(0, 1, 2)  | 2
// | 5 | point(0, -1, -2) | vector(0, 1, 1)  | 2 

// | 1 | point(0, 3, 0)   | vector(0, -1, 0) | 2 
Test(capped_cylinders, intersecting_caps, .description = scenario2) {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, 3, 0, POINT},
		.direction = {0, -1, 0, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	cr_assert_eq(xs.count, 2);
}

// | 2 | point(0, 3, -2)  | vector(0, -1, 2) | 2
Test(capped_cylinders, intersecting_caps2) {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, 3, -2, POINT},
		.direction = {0, -1, 2, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	cr_assert_eq(xs.count, 2);
}

// | 3 | point(0, 4, -2)  | vector(0, -1, 1) | 2
Test(capped_cylinders, intersecting_caps3) {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, 4, -2, POINT},
		.direction = {0, -1, 1, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	cr_assert_eq(xs.count, 2);
}

// | 4 | point(0, 0, -2)  | vector(0, 1, 2)  | 2
Test(capped_cylinders, intersecting_caps4) {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, 0, -2, POINT},
		.direction = {0, 1, 2, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	cr_assert_eq(xs.count, 2);
}

// | 5 | point(0, -1, -2) | vector(0, 1, 1)  | 2 
Test(capped_cylinders, intersecting_caps5) {
	t_cylinder cyl = create_cylinder();
	const t_ray r = {
		.origin = {0, -1, -2, POINT},
		.direction = {0, 1, 1, VECTOR}
	};

	cyl.closed = TRUE;
	set_cyl_min_max(&cyl, 1, 2);
	t_intersection xs = create_intersection(&cyl, r);
	cr_assert_eq(xs.count, 2);
}
