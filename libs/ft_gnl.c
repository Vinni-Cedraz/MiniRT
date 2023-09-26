/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 23:04:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reading_function(int fd);
static char	*linebreaker(char *wth_all, size_t wth_all_len, size_t aft_or_not);

char	*ft_gnl(int fd)
{
	t_gnl		line;
	static char	*aftbrk[1024];

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line.bfr_brk = NULL;
	if (!aftbrk[fd])
		line.wth_all = reading_function(fd);
	else
		line.wth_all = ft_strjoin(aftbrk[fd], reading_function(fd));
	line.len = ft_strlen(line.wth_all) + 1;
	if (line.len - 1)
	{
		aftbrk[fd] = linebreaker(line.wth_all, line.len, 1);
		line.bfr_brk = linebreaker(line.wth_all, line.len, 0);
	}
	if (!(line.wth_all == line.bfr_brk))
		free(line.wth_all);
	return (line.bfr_brk);
}

static char	*reading_function(int fd)
{
	t_gnl	line;

	line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	line.bfr_brk = malloc(sizeof(char));
	line.len = read(fd, line.read, BUFFER_SIZE);
	*line.bfr_brk = '\0';
	while (line.len != 0)
	{
		*(line.read + line.len) = '\0';
		line.bfr_brk = ft_strjoin(line.bfr_brk, line.read);
		if (ft_memchr(line.bfr_brk, '\n', ft_strlen(line.bfr_brk)))
			break ;
		line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
		line.len = read(fd, line.read, BUFFER_SIZE);
	}
	if (line.len == 0)
		free(line.read);
	return (line.bfr_brk);
}

// wth_all_len already has the +1 for the \0
static char	*linebreaker(char *wth_all, size_t wth_all_len, size_t aft_or_not)
{
	t_gnl	line;

	line.lnbrk = ft_memchr(wth_all, '\n', wth_all_len);
	if (aft_or_not == 1)
	{
		line.aftbrk_len = (wth_all + wth_all_len) - (line.lnbrk + 1);
		if (!line.lnbrk || line.lnbrk == wth_all + wth_all_len)
			return (NULL);
		line.aftbrk = malloc((line.aftbrk_len + 1) * sizeof(char));
		ft_memcpy(line.aftbrk, line.lnbrk + 1, line.aftbrk_len);
		return (line.aftbrk);
	}
	line.bfrbrk_len = line.lnbrk - wth_all + 2;
	if (!line.lnbrk || line.lnbrk == wth_all + wth_all_len)
		return ((char *)wth_all);
	line.bfr_brk = malloc((line.bfrbrk_len) * sizeof(char));
	ft_memcpy(line.bfr_brk, wth_all, line.bfrbrk_len);
	*(line.bfr_brk + line.bfrbrk_len - 1) = '\0';
	return (line.bfr_brk);
}
