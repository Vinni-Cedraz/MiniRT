/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:53:26 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/05 10:35:51 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"
#include "minirt.h"
#include <fcntl.h>

static int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Arquivo nao encontrado\n");
		return (0);
	}
	return (fd);
}

static void	load_data(char *str, t_node *node)
{
	t_parse_table	**apply;
	int				count;

	apply = get_parser_table();
	count = 0;
	while (1)
	{
		apply[count](str, node);
	}
}

int	parse_file(char *file)
{
	int		fd;
	char	*line;
	t_node	*head;

	head = NULL;
	fd = open_file(file);
	line = ft_gnl(fd);
	while (line != NULL)
	{
		printf("%s", line);
		load_data(line, head);
		line = ft_gnl(fd);
	}
	return (1);
}
