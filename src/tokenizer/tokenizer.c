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

static void		set_token(t_token *token, t_split *spl, int fd, char *line);
static t_token	*safe_calloc(size_t size, int fd);
static void		init_token_args(t_split *spl, int fd, char *ln, t_token *token);
static void		incorrect_line_size_error(char *ln, t_split *spl, int fd);

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
			set_token(&tokens[idx], splitted, fd, line);
			idx++;
		}
		free(line);
		ft_free_t_split(splitted);
		line = ft_gnl(fd);
	}
	close(fd);
	return (tokens);
}

static void	set_token(t_token *token, t_split *spl, int fd, char *line)
{
	static char		identifier[] = {'A', 'C', 'L', 's', 'p', 'c'};
	static t_type	type[] = {AMBIENT, CAMERA, LIGHT, SPHERE, PLANE, CYLINDER};
	int				i;

	i = -1;
	while (++i < 6)
	{
		if (spl->words[0][0] == identifier[i])
		{
			token->type = type[i];
			init_token_args(spl, fd, line, token);
		}
	}
}

static void	init_token_args(t_split *spl, int fd, char *ln, t_token *token)
{
	static int	nb_of_args[] = {2, 3, 2, 3, 3, 5};
	int			len;
	int			idx;

	idx = -1;
	if ((int)spl->count - 1 != nb_of_args[token->type])
		incorrect_line_size_error(ln, spl, fd);
	while (++idx < (int)spl->count)
	{
		len = ft_strlen(spl->words[idx + 1]);
		if (len > 24)
			incorrect_line_size_error(ln, spl, fd);
		ft_strlcpy(token->args[idx], spl->words[idx + 1], len + 1);
	}
}

static void	incorrect_line_size_error(char *ln, t_split *spl, int fd)
{
	printf(RED "Error, incorrect line: %s\n" RESET, ln);
	free_and_exit_error(ln, spl, fd);
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
