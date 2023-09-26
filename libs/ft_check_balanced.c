/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_balanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:04:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/07 21:04:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int	is_open_meta(char c);
static int	is_closed_meta(char c);
static int	stack_is_empty(t_node *stack);
static int	metas_are_paired(char close, char *open);

int	ft_check_balanced(char expression[])
{
	int		i;
	t_node	*stack;
	char	c;

	i = -1;
	stack = ft_lstnew((void *){0});
	while (expression[++i])
	{
		if (is_open_meta(expression[i]))
		{
			c = expression[i];
			ft_lstadd_front(&stack, ft_lstnew(&c));
		}
		else if (is_closed_meta(expression[i]))
		{
			if (stack_is_empty(stack))
				return (0);
			else if (metas_are_paired(expression[i], stack->content))
				stack = ft_lstpop(&stack);
		}
	}
	if (stack_is_empty(stack))
		return (1);
	return (0);
}

static int	is_open_meta(char c)
{
	return (c == '{' || c == '[' || c == '(');
}

static int	is_closed_meta(char c)
{
	return (c == '}' || c == ']' || c == ')');
}

static int	stack_is_empty(t_node *stack)
{
	return (1 == ft_lstsize(stack));
}

static int	metas_are_paired(char close, char *open)
{
	if (*open == '{' && close == '}')
		return (1);
	if (*open == '[' && close == ']')
		return (1);
	if (*open == '(' && close == ')')
		return (1);
	return (0);
}

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
// #include "ft_lstadd_front.c"
// #include "ft_lstnew.c"
// #include "ft_lstpop.c"
// #include "ft_lstprint.c"
// #include "ft_lstsize.c"
// #include "ft_strdup.c"
// #include "ft_strlen.c"
// int	main(void)
// {
// 	char	*valid_expression;
// 	char	*invalid_expression;
// 	char	*invalid_expression2;
// 	char	*invalid_expression3;
// 	char	*invalid_expression4;
// 	char	*valid_expression5;
// 	char	*invalid_expression6;
// 	char	*invalid_expression7;
//
// 	valid_expression = ft_strdup("${variavel} && $(comando)");
// 	invalid_expression = ft_strdup("${variavel} && $comando)");
// 	invalid_expression2 = ft_strdup("${variavel) && $(comando|]}");
// 	invalid_expression3 = ft_strdup("${variavel)} && $(comando|]}");
// 	invalid_expression4 = ft_strdup("${variavel})} && $(comando|]}");
// 	valid_expression5 = ft_strdup("()()(){}{}{}[][][]");
// 	invalid_expression6 = ft_strdup("(((}}");
// 	invalid_expression7 = ft_strdup("(((}}}");
// 	assert(ft_check_balanced(invalid_expression) == 0);
// 	assert(ft_check_balanced(invalid_expression2) == 0);
// 	assert(ft_check_balanced(invalid_expression3) == 0);
// 	assert(ft_check_balanced(invalid_expression4) == 0);
// 	assert(ft_check_balanced(invalid_expression6) == 0);
// 	assert(ft_check_balanced(invalid_expression7) == 0);
// 	assert(ft_check_balanced(valid_expression5) == 1);
// 	assert(ft_check_balanced(valid_expression) == 1);
// 	printf("tests passed!\n");
// }
