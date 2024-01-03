/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:25:40 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera(char *str, t_parsectx *ctx)
{
	if (ft_strncmp(str, CAMERA_ID, STR_LEN) != 0)
		return;
	printf("camera\n");
	(void)ctx;
	(void)str;
}
