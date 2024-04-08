#include "../../tester.h"
#include <stdio.h>

// Scenario : The hit, when all intersections have positive t
#define scenario1 CYAN \
"Given s ← sphere()\n" \
"And i1 ← ft_lstnew(1, s)\n" \
"And i2 ← ft_lstnew(2, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← get_hit(xs)\n" \
"Then hit = i1\n" RESET

Test(identifying_hits, positive_t, .description = scenario1) {
	t_intersections intersections;
	t_sphere s = create_sphere();
	intersections.head = ft_lstnew(1, &s);
	ft_lstadd_back(&intersections.head, ft_lstnew(2, &s));
	intersections.count = 2;
	const t_node hit = _hit(intersections);
	cr_expect_eq(hit.t, 1);
}

// Scenario : The hit, when some intersections have negative t
#define scenario2 CYAN \
"Given s ← sphere()\n" \
"And i1 ← ft_lstnew(-1, s)\n" \
"And i2 ← ft_lstnew(1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← _hit(xs)\n" \
"Then hit = i2\n" RESET

Test(identifying_hits, negative_t, .description = scenario2)
{
	t_sphere s = create_sphere();
	t_intersections intersections;
	intersections.head = ft_lstnew(1, &s);
	ft_lstadd_back(&intersections.head, ft_lstnew(-1,&s));
	intersections.count = 2;
	const t_node hit = _hit(intersections);
	cr_expect_eq(hit.t, 1);
}

// Scenario : The hit, when all intersections have negative t
#define scenario3 CYAN \
"Given s ← sphere()\n" \
"And i1 ← ft_lstnew(-2, s)\n" \
"And i2 ← ft_lstnew(-1, s)\n" \
"And xs ← intersections(i2, i1)\n" \
"When hit ← _hit(xs)\n" \
"Then hit is nothing\n" RESET

Test(identifying_hits, all_negatives, .description = scenario3)
{
	t_sphere s = create_sphere();
	t_intersections intersections;
	intersections.head = ft_lstnew(-1, &s);
	ft_lstadd_back(&intersections.head, ft_lstnew(-2, &s));
	intersections.count = 2;
	const t_node hit = _hit(intersections);
	cr_expect_eq(hit.object, NULL);
}

// Scenario : The hit is always the lowest nonnegative ft_lstnew
#define scenario4 CYAN \
"Given s ← sphere()\n" \
"And i1 ← ft_lstnew(5, s)\n" \
"And i2 ← ft_lstnew(7, s)\n" \
"And i3 ← ft_lstnew(-3, s)\n" \
"And i4 ← ft_lstnew(2, s)\n" \
"And xs ← intersections(i1, i2, i3, i4)\n" \
"When hit ← _hit(xs)\n" \
"Then hit = i4\n" RESET

Test(identifying_hits, hit_is_alway_lowest_nonnegative_intersection, .description = scenario4)
{
	t_sphere s = create_sphere();
	t_intersections intersections;

	intersections.head = ft_lstnew(5, &s);
	ft_lstadd_back(&intersections.head, ft_lstnew(7, &s));
	ft_lstadd_back(&intersections.head, ft_lstnew(-3, &s));
	ft_lstadd_back(&intersections.head, ft_lstnew(2, &s));
	intersections.count = 4;

	const t_node hit = _hit(intersections);
	cr_expect_eq(hit.t, 2);
}
