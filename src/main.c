#include "minirt.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init(800, 900, "MLX", 1);
	mlx_win = mlx_new_image(mlx, 800, 900);
	mlx_loop(mlx);
	printf("%d", USE_CODAM);
}
