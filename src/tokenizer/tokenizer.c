/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:42:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/14 19:20:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_token(t_token *token, t_tokenizer tokenizer);
static t_token	*safe_calloc(size_t size, int fd);
static void		init_token_args(t_tokenizer tokenizer, t_token *token);
static void		incorrect_line_size_error(t_tokenizer tokenizr, _Bool sz_error);

t_token	*tokenizer(int fd, int number_of_tokens)
{
	char	*line;
	t_split	*splitted;
	t_token	*tokens;
	int		idx;

	idx = 0;
	tokens = safe_calloc(number_of_tokens, fd);
	line = ft_gnl(fd);
	while (line)
	{
		splitted = ft_split(line, ' ');
		if (line[0] != '\n')
		{
			set_token(&tokens[idx], (t_tokenizer){splitted, line, fd, tokens});
			idx++;
		}
		free(line);
		ft_free_t_split(splitted);
		line = ft_gnl(fd);
	}
	close(fd);
	return (tokens);
}

static void	set_token(t_token *token, t_tokenizer tokenizer)
{
	static char		identifier[] = {'A', 'C', 'L', 's', 'p', 'c'};
	static t_type	type[] = {AMBIENT, CAMERA, LIGHT, SPHERE, PLANE, CYLINDER};
	int				i;

	i = -1;
	while (++i < 6)
	{
		if (tokenizer.splitted->words[0][0] == identifier[i])
		{
			token->type = type[i];
			init_token_args(tokenizer, token);
		}
	}
}

static void	init_token_args(t_tokenizer tokenizer, t_token *token)
{
	static int	nb_of_args[] = {2, 3, 2, 3, 3, 5};
	int			len;
	int			idx;

	idx = -1;
	if ((int)tokenizer.splitted->count - 1 != nb_of_args[token->type])
		incorrect_line_size_error(tokenizer, 0);
	while (++idx < (int)tokenizer.splitted->count)
	{
		len = ft_strlen(tokenizer.splitted->words[idx + 1]) + 1;
		if (len > 24)
			incorrect_line_size_error(tokenizer, 1);
		ft_strlcpy(token->args[idx], tokenizer.splitted->words[idx + 1], len);
	}
}

static void	incorrect_line_size_error(t_tokenizer tokenizer, _Bool size_error)
{
	if (size_error)
		printf(RED "Error, line too long: %s" RESET, tokenizer.line);
	else
		printf(RED "Error, wrong number of args: %s" RESET, tokenizer.line);
	free(tokenizer.tokens);
	free_and_exit_error(tokenizer.line, tokenizer.splitted, tokenizer.fd);
}

static t_token	*safe_calloc(size_t size, int fd)
{
	t_token	*tokens;

	tokens = calloc(sizeof(t_token), size + 1);
	if (tokens == NULL)
	{
		close(fd);
		perror("calloc failed");
		exit(1);
	}
	return (tokens);
}
