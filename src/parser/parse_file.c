/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:53:26 by johmatos          #+#    #+#             */
/*   Updated: 2023/12/19 19:22:53 by vcedraz-         ###   ########.fr       */
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

static size_t get_total_of_lines(char *str)
{
	int		fd;
	char 	*line;
	size_t	count;

	fd = open_file(str);
	count = 0;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = ft_gnl(fd);
	}
	return (count);
}
static void	load_data(char *str, t_parsectx *ctx)
{
	const t_idtable		*object = get_parser_table();
	int				count;

	count = -1;
	while (++count < TOTAL_OBJS)
	{
		if (ft_strcmp(object[count].id, str) == 0)
		{
			printf("%s\n", object[count].id);
			object[count].apply(str, ctx);
		}
	}
}

t_world	*parse_file(char *file)
{
	int				fd;
	size_t 			lines;
	t_shape 		*shapes;
	t_parsectx		ctx;
	char			*line;


	lines = get_total_of_lines(file);
	shapes = ft_calloc(sizeof(t_shape), lines);
	fd = open_file(file);
	ctx.line = 0;
	ctx.shape_list = shapes;
	line = ft_gnl(fd);
	while (line != NULL)
	{
		load_data(line, &ctx);
		free(line);
		line = ft_gnl(fd);
		ctx.line++;
	}
	return (NULL);
}

// #include "../../tests/tester.h"
//
// Test(pattern_match, id, .description = "check id of obj")
// {
// 	t_node *head = NULL;
// 	char *str = "sp 0,0,20 20 255,0,0";
//
// 	load_data(str, head);
// }
