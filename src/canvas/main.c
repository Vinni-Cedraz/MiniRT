#include "minirt.h"
#include <string.h>

typedef struct s_projectile {
    t_tuple position;
    t_tuple velocity;
} t_projectile;

typedef struct s_environment {
    t_tuple gravity;
    t_tuple wind;
} t_environment;

static inline void create_ppm_file(t_constr ppm_string) {
    int fd = open("CANVAS.ppm", O_CREAT | O_RDWR);
    write(fd, ppm_string, strlen(ppm_string));
    close(fd);
}

static inline int invert_axis(int size, float axis) {
	int res;

	res = ((int)size - (int)axis);
	return res;
}

t_projectile tick(t_environment env, t_projectile projectile) {
    t_projectile p;

    add_tuples(projectile.position, projectile.velocity, p.position);
    add_tuples(projectile.velocity, env.gravity, p.velocity);
    add_tuples(p.velocity, env.wind, p.velocity);
    return (p);
}

static void normalize_rgb(t_tuple raw_rgb)
{
	raw_rgb[X] = raw_rgb[X] / 255;
	raw_rgb[Y] = raw_rgb[Y] / 255;
	raw_rgb[Z] = raw_rgb[Z] / 255;
}

int main(void) {
	t_tuple color = {161, 201, 247, COLOR};
    t_canvas c = create_canvas(1080, 1920);
	// const t_sphere ball = create_sphere();
	normalize_rgb(color);
	// paint canvas
	for (int i = 0; i < 1079; i++) {
		for (int j = 0; j < 1919; j++) {
			int y = invert_axis(c.height, i);
			int x = invert_axis(c.width, j);
        	write_pixel(&c, y - 1, x - 1, color);
		}
	}

    t_constr ppm_string = canvas_to_ppm(&c);
    create_ppm_file(ppm_string);
	destroy_canvas(&c);
}
