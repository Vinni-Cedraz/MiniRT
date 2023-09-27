/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/26 13:20:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	expand_format_str(t_strings *strs, char *result);

char	*ft_fmt_str(t_constr format, t_constr s1, t_constr s2, t_constr s3)
{
	int			i;
	int			format_idx;
	char		result[STR_LIMIT];
	t_strings	strs;

	i = 0;
	format_idx = 0;
	ft_bzero(result, STR_LIMIT);
	strs = (t_strings){.a = s1, .b = s2, .c = s3};
	while (format[format_idx])
	{
		if (format[format_idx] == '%' && format[format_idx + 1] == 's')
		{
			if (strs.a)
				expand_format_str(&strs, result);
			format_idx += 2;
			i = ft_strlen(result);
		}
		else
			result[i++] = format[format_idx++];
	}
	return (ft_strdup(result));
}

static void	expand_format_str(t_strings *strs, char *result)
{
	ft_strlcat(result, strs->a, STR_LIMIT);
	strs->a = strs->b;
	strs->b = strs->c;
	strs->c = NULL;
}
