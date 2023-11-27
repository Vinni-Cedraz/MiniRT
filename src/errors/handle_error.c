/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:14:10 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/26 11:23:10 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**get_error(void)
{
	static char	*error = NULL;

	return (&error);
}

void	set_error(char *str)
{
	*get_error() = str;
}

void	print_error(void)
{
	printf("%s\n", *get_error());
}
