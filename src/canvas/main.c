#include "canvas_to_ppm.c"

static inline void set_all_pixels_to_one_color(const t_canvas *c, t_tuple color) {
    for (int y = 0; y < c->height; y++)
        for (int x = 0; x < c->width; x++)
            write_pixel((t_canvas *)c, y, x, color);
}

static inline void create_ppm_file(t_constr ppm_string, const char filename[]) {
	size_t len = ft_strlen(ppm_string) + ft_strlen(filename) + 10;
	char *cmd = ft_calloc(len, sizeof(char));
	sprintf(cmd, "echo '%s' > %s", ppm_string, filename);
	system(cmd);
	free(cmd);
}

int main() {
	const t_canvas 				c = create_canvas(55, 90);

	set_all_pixels_to_one_color(&c, (t_tuple){1.0, 0.8, 0.6});
	t_constr pxls_str = canvas_to_ppm(&c);
	create_ppm_file(pxls_str, "main_canvas.ppm");
	destroy_canvas(&c);
}
