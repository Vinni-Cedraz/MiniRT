/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_orientation_vector.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:43:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/05/01 18:44:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_tuple	dest;
	t_tuple	src;
	t_tuple	vector;
	t_tuple	unit_vector;

	if (argc != 3)
	{
		printf(GREEN \
"usage: ./create_orientation_vector \'destination point\' \'source point\'"RESET
			);
		return (1);
	}
	dest = parse_tuple(argv[1], POINT);
	src = parse_tuple(argv[2], POINT);
	vector = subtract_tuples(dest, src);
	unit_vector = normalize(vector);
	print_tuple(unit_vector);
}
