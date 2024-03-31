#include "stdio.h"
# include "include/minirt.h"

int main ()
{
	t_matrix a ={
			.grid =
					{
				{-2, -8, 3, 5},
				{-3, 1, 7, 3},
				{1, 2, -9, 6},
				{-6, 7, 7, -9}
			},
				.size = 4
	};

	return (printf("%f\n", _determinant_test(a, a.grid[0])));
}