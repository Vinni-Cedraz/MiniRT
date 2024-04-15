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

static void		set_token(t_token *token, t_split *spl);
static t_token	*safe_calloc(size_t size, int fd);

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
			set_token(&tokens[idx], splitted);
			idx++;
		}
		free(line);
		ft_free_t_split(splitted);
		line = ft_gnl(fd);
	}
	close(fd);
	return (tokens);
}

static void	set_token(t_token *token, t_split *spl)
{
	static char		identifier[] = {'A', 'C', 'L', 's', 'p', 'c'};
	static t_type	type[] = {AMBIENT, CAMERA, LIGHT, SPHERE, PLANE, CYLINDER};
	int				len;
	int				i;
	int				j;

	i = -1;
	j = -1;
	while (++i < 6)
	{
		if (spl->words[0][0] == identifier[i])
		{
			token->type = type[i];
			while (++j < (int)spl->count)
			{
				len = ft_strlen(spl->words[j + 1]);
				ft_strlcpy(token->args[j], spl->words[j + 1], len + 1);
			}
		}
	}
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
