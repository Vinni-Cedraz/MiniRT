#include "minirt.h"

t_canvas render_world01(t_world *world)
{
    t_camera camera = create_camera(480, 240, M_PI / 3);
    t_tuple from = (t_tuple){0, 1.5, 7, POINT};
    t_tuple to = (t_tuple){0, 1, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    return(render(camera, *world));
}

t_canvas render_world02(t_world *world)
{
    t_camera camera = create_camera(480, 240, M_PI / 3);
    t_tuple from = (t_tuple){0, 10, 0, POINT};
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 0, -1, VECTOR};
    t_tuple forward;

    subtract_tuples(to, from, forward);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);

    return(render(camera, *world));
}
