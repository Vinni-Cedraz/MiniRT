#include "../../tests/tester.h"
#include "minirt.h"

#define scale 3
int main(void) {
    t_sphere white_ball = create_sphere();
    t_sphere red_ball = create_sphere();
    t_world world;

    set_transform(&red_ball, create_scaling_matrix(scale, scale, scale));
    set_transform(&red_ball, create_translation_matrix((t_tuple){0, 0, -20, POINT}));
    set_transform(&white_ball, create_translation_matrix((t_tuple){3, 0, -10, POINT}));
    set_material((t_tuple){0.1, 0.9, 0.9, 200}, (t_tuple){1, 0, 0}, &red_ball.material);

    world.objs = malloc(sizeof(t_sphere) * 6);
    world.count = 2;
    world.objs[0] = white_ball;
    world.objs[1] = red_ball;
    world.light = &(t_point_light){
        {-10, 10, -10, POINT},
        {1, 1, 1, COLOR},
    };

    t_camera camera = create_camera(540, 960, M_PI / 3);
    t_tuple from = (t_tuple){0, 0, 0, POINT};
    t_tuple to = (t_tuple){0, 0, -1, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, world);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str);
    destroy_canvas(&c);
}
