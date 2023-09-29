#include "minirt.h"

int	main(void)
{
	mlx_t*	mlx;

	mlx_init(900, 900, "MLX42", true);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
