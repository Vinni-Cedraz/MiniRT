/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiente_lightning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:52 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 20:35:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_lightning(char *str, t_parsectx *ctx)
{
	if (ft_strncmp(str, A_LIGHT_ID, STR_LEN) != 0)
		return;
	printf("ambient\n");
	(void)ctx;
	(void)str;
}
