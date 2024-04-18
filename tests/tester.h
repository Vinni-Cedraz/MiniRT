#ifndef TEST_H
#define TEST_H

#include "../include/minirt.h"
#include <criterion/criterion.h>
#include <stdio.h>
#define CYAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[0m"

static inline void	print_tokens(t_token *tokens, int nb)
{
	int			i;
	int			j;
	const char	identifiers[6][9] = {\
			"AMBIENT", "CAMERA", "LIGHT", "SPHERE", "PLANE", "CYLINDER"};

	i = 0;
	while (i < nb)
	{
		printf("Token %d:\n", i + 1);
		printf("  Type: %s\n", identifiers[tokens[i].type]);
		j = 0;
		while (&tokens[i] && j < 5 && tokens[i].args[j][0] != '\0')
		{
			printf("  Arg %d: %s\n", j + 1, tokens[i].args[j]);
			j++;
		}
		i++;
	}
}

static inline void print_world(t_world world) {
    printf("World:\n");

    // Camera Information
    printf("  Camera:\n");
    printf("    hsize: %f\n", world.camera.hsize);
    printf("    vsize: %f\n", world.camera.vsize);
    printf("    half_width: %f\n", world.camera.half_width);
    printf("    half_height: %f\n", world.camera.half_height);
    printf("    field_of_view: %f\n", world.camera.field_of_view);
    printf("    transform:\n");
    print_matrix(world.camera.transform);
    printf("    pixel_size: %f\n", world.camera.pixel_size);
    printf("    xoffset: %f\n", world.camera.xoffset);
    printf("    yoffset: %f\n", world.camera.yoffset);
    printf("    world_x: %f\n", world.camera.world_x);
    printf("    world_y: %f\n", world.camera.world_y);
	printf("    up: (%f, %f, %f)\n", world.camera.up.x, world.camera.up.y, world.camera.up.z);

    // Light Information
    printf("  Light:\n");
    printf("    position:\n");
    print_tuple(world.light.position);
    printf("    intensity:\n");
    print_tuple(world.light.intensity);
	printf("    ambient factor:\n");
	print_tuple(world.ambient);

    // Objects 
    printf("  Objects:\n");
	printf(RED"WORLD COUNT: %d\n"RESET, world.count);
    for (int i = 0; i < world.count; i++) {
        printf("    Object %d (Sphere):\n", i);
        printf("      transform:\n");
        print_matrix(world.objs[i]._t);
        printf("      inverse_t:\n");
        print_matrix(world.objs[i].inverse_t);
        printf("      trans_inv:\n");
        print_matrix(world.objs[i].trans_inv); // Added!
        printf("      dis_to_ray:\n");
        print_tuple(world.objs[i].dis_to_ray);  // Added!
        printf("      origin:\n");
        print_tuple(world.objs[i].origin);      // Added!
        printf("      radius: %d\n", world.objs[i].radius);       // Added!
        printf("      id: %d\n", world.objs[i].id); 
        printf("      type: %d\n", world.objs[i].type);         // Added!
        printf("      material:\n");
        printf("        ambient: %f\n", world.objs[i].material.ambient);
        printf("        diffuse: %f\n", world.objs[i].material.diffuse);
        printf("        specular: %f\n", world.objs[i].material.specular);
        printf("        shininess: %f\n", world.objs[i].material.shininess);
        printf("        color:\n"); 
        print_tuple(world.objs[i].material.color);
    }
}
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

static inline int invert_axis(int size, double axis) { return ((int)size - axis); }

#endif
