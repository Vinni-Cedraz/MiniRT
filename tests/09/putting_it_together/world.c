#include "tester.h"

t_world init_world(t_shape *floor, t_sphere *balls[], t_plane *walls[6]) {
	t_world world;

    world.objs = malloc(sizeof(t_sphere) * (walls?10:4));
    world.count = (walls?10:4);
    world.objs[0] = *floor;
    world.objs[1] = *(t_shape *)balls[0];
    world.objs[2] = *(t_shape *)balls[1];
    world.objs[3] = *(t_shape *)balls[2];
	if (walls) {
		world.objs[4] = *(t_shape *)walls[0];
		world.objs[5] = *(t_shape *)walls[1];
		world.objs[6] = *(t_shape *)walls[2];
		world.objs[7] = *(t_shape *)walls[3];
		world.objs[8] = *(t_shape *)walls[4];
		world.objs[9] = *(t_shape *)walls[5];
	}
	world.light = malloc(sizeof(t_point_light));
    world.light[0] = (t_point_light){
        {10, 100, 30, POINT},
        {1, 1, 1, COLOR},
    };
	return (world);
}
