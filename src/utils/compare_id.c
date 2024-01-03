/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:27:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/26 17:32:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *minor, const char *major)
{
	size_t	i;
	int		difference;

	i = 0;
	difference = 0;
	while (minor[i] && minor[i] == major[i])
		i++;
	if (i > 0)
		i--;
	difference = (unsigned char)minor[i] - (unsigned char)major[i];
	return (difference);
}
