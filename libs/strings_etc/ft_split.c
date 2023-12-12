/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:49:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 17:44:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			aux_strlen(const char *str);
static void				*aux_calloc(size_t nmemb, size_t size);
static void				*aux_memcpy(void *dst, const void *src, size_t n);
static char				*aux_substr(char const *s, t_uint start, size_t len);

t_split	*ft_split(char const *s, char c)
{
	t_split	*tool;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	tool = (t_split *)malloc(sizeof(t_split));
	tool->words = ft_word_counter(s, c);
	tool->start = (char *)s;
	tool->end = tool->start;
	tool->str_arr = (char **)aux_calloc(tool->words + 1, sizeof(char *));
	while (++i < tool->words)
	{
		while (*tool->end == c && tool->end++)
			if (*tool->end != c)
				tool->start = tool->end;
		tool->end = ft_memchr(tool->start, c, aux_strlen(tool->start));
		if (!tool->end)
			tool->end = tool->end + aux_strlen(tool->start);
		tool->str_arr[i] = aux_substr(tool->start, 0, tool->end - tool->start);
	}
	return (tool);
}

static size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static void	*aux_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
		*(dest + i) = *(source + i);
	return (dest);
}

static char	*aux_substr(char const *s, t_uint start, size_t len)
{
	char	*substr;
	t_uint	s_len;

	s_len = (t_uint)aux_strlen(s);
	if (start > s_len)
		return (malloc(0));
	else if (len > s_len - start)
	{
		substr = malloc((s_len - start + 1) * sizeof(char));
		aux_memcpy(substr, s + start, s_len - start);
		substr[s_len - start] = '\0';
		return (substr);
	}
	else
	{
		substr = malloc((len + 1) * sizeof(char));
		aux_memcpy(substr, s + start, len);
		substr[len] = '\0';
		return (substr);
	}
}

static void	*aux_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!size || !nmemb)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	while (i < size * nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
