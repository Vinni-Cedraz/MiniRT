/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:47:50 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 17:49:13 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

// Scenario: Creating and querying a ray

# define scenario1 CYAN \
"\nGiven origin ← point(1, 2, 3)\n" \
"And direction ← vector(4, 5, 6)\n" \
"When r ← ray(origin, direction)\n" \
"Then r.origin = origin\n"          \
"And r.direction = direction\n"
