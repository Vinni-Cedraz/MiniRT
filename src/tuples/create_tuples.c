/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:27:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/26 18:27:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_point(t_tuple tuple)
{
	tuple[W] = 1;
}

void	create_vector(t_tuple tuple)
{
	tuple[W] = 0;
}
