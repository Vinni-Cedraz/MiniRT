/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:16:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/25 18:03:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define STR1 "Invalid arguments\n"

int	main(int argc, char * argv[])
{
	if (argc != 2)
		return (printf(STR1));
	if (validate_argument(argv[1]) != TRUE)
		return(printf("Incorrect file format\n"));
	(void)argv;
}
