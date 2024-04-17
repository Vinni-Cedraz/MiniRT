/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:43 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/14 18:48:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
void print_world(t_world world);

int	main(int argc, char **argv)
{
	int			fd;
	int			number_of_tokens;
	t_token		*tokens;
	t_world		world;

	fd = 0;
	number_of_tokens = 0;
	if (argc != 2)
		return (0);
	if (!endwith(argv[1], ".rt"))
		printf("Arquivo nao .rt\n");
	fd = open_file(argv[1]);
	file_validation(fd, &number_of_tokens);
	fd = open_file(argv[1]);
	tokens = tokenizer(fd, number_of_tokens);
	print_tokens(tokens, number_of_tokens);
	world = parse_tokens_into_world(tokens);
	print_world(world);
	free(tokens);
}

void	print_tokens(t_token *tokens, int nb)
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

void print_world(t_world world) {
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

    // Light Information
    printf("  Light:\n");
    printf("    position:\n");
    print_tuple(world.light.position);
    printf("    intensity:\n");
    print_tuple(world.light.intensity);

    // Objects 
    printf("  Objects:\n");
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
