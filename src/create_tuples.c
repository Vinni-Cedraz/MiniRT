#include "../include/minirt.h"

t_tuple create_a_point(t_tuple *tuple)
{
	tuple->w = 1;
	return (*tuple);
}

t_tuple create_a_vector(t_tuple *tuple)
{
	tuple->w = 0;
	return (*tuple);
}
