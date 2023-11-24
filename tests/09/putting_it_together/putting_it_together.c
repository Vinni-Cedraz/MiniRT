#include "tester.h"

#include "balls.c"
#include "walls.c"
#include "world.c"
#include "floor.c"
#include "render.c"

Test(plane, spheres_on_a_plane_floor) {
    t_sphere left_ball = create_sphere();
    t_sphere right_ball = create_sphere();
    t_sphere middle_ball = create_sphere();
	t_plane	 floor = create_plane();
    t_world  world;

	// FLOOR
	init_tuple((t_tuple){1, 0.9, 0.9, COLOR}, floor.material.color);
	floor.material.specular = 0;

	// BALLS
	init_test1_balls((t_sphere *[]){
			&left_ball, &right_ball, &middle_ball
	});
	
	world = init_world(
		(t_shape *)&floor,
		(t_sphere *[]){&left_ball, &right_ball, &middle_ball},
		NULL
	);

	t_canvas canvas = render_world01(&world);

    char *str = canvas_to_ppm(&canvas);
    create_ppm_file(str, "spheres_floor_plane.ppm");
    destroy_canvas(&canvas);
}

Test(plane, spheres_on_floor_from_above) {
	t_sphere right_ball = create_sphere();
	t_sphere middle_ball = create_sphere();
	t_sphere left_ball = create_sphere();

    char *ppm_str;
	t_canvas canvas;
	t_plane floor = create_plane();
    t_world world;

	// CREATE SHAPES
	init_floor((t_shape *)&floor);
	init_test2_balls((t_sphere *[]){
			&right_ball, &left_ball, &middle_ball
	});

	// init_walls(walls);
	t_plane **walls = NULL;
	world = init_world(
			(t_shape *)&floor,
			(t_sphere *[]){&right_ball, &left_ball, &middle_ball},
			walls
	);

	// RAY TRACE THE SHAPES INTO A CANVAS
	canvas = render_world02(&world);

	// CREATE IMAGE FILE
	ppm_str = canvas_to_ppm(&canvas);
    create_ppm_file(ppm_str, "spheres_on_floor_from_above.ppm");
    destroy_canvas(&canvas);
}
