#include "../tests/tester.h"

void quick_render(t_world *w) {

    t_camera camera = create_camera(480, 280, M_PI / 4);
    t_tuple from = (t_tuple){-1.5, -15, 10, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 0, 1, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    t_canvas c = render(camera, *w);

    char *str = canvas_to_ppm(&c);
    create_ppm_file(str, "main.ppm");
    destroy_canvas(&c);
    free(str);
    free(w->objs);
}
