#include "minirt.h"
#include <stdio.h>

int main() {
	double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	t_matrix teste = create_matrix(array);

	printf("O tamanho do array é: %d bytes\n", teste.size);

	return 0;
}
