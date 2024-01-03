/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:03:17 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/26 17:29:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "minirt_defines.h"
#include <stdio.h>


// static t_bool valid_id(char **str, t_parsectx *context, char *id)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (str && **str && **str != ' ' && i < ft_strlen(id))
// 		i++;
// 	*str = *str + i;
// 	context->column += i;
// 	if (*str && **str == ' ')
// 		return (TRUE);
// 	context->err = TRUE;
// 	return (FALSE);
// }

void	parse_sphere(char *str, t_parsectx *ctx)
{
	char 		*aux;

	if (ft_strncmp(str, SPHERE_ID, ft_strlen(SPHERE_ID)) != 0)
		return;
	str = str + 3;
	aux = str;
	while (*aux !=  ' ')
		aux++;
	(void)ctx;
}


// # include "../../tests/tester.h"
//
// Test(test_valid_id, geral, .description = "valid id")
// {
// 	char * str = "sp 0,0,20 20 255,0,0";
// 	t_parsectx ctx;
// 	ctx.column = 0;
// 	ctx.line = 0;
// 	ctx.err = FALSE;
// 	t_bool valid = valid_id(&str, &ctx, SPHERE_ID);
// 	cr_expect_eq(valid, TRUE);
// 	cr_expect_eq(ctx.column, 2);
// }
//
// Test(test_invalid_id, geral, .description = "invalid id")
// {
// 	char * str = "ab 0,0,20 20 255,0,0";
// 	t_parsectx ctx;
// 	ctx.column = 0;
// 	ctx.line = 0;
// 	ctx.err = TRUE;
// 	t_bool valid = valid_id(&str, &ctx, SPHERE_ID);
// 	cr_expect_neq(valid, TRUE);
// 	cr_expect_eq(ctx.column, 2);
// 	cr_expect_eq(ctx.err, TRUE);
// }
