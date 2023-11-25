/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:54:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/25 18:00:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_argument(char *argv)
{
	while (*argv != '.')
		argv++;
	argv++;
	if (*argv != 'r')
		return (FALSE);
	argv++;
	if (*argv != 't')
		return (FALSE);
	argv++;
	if (*argv != '\0')
		return (FALSE);
	return (TRUE);
}
