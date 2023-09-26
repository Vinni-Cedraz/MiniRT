/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:51:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 13:02:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned int	t_uint;
typedef unsigned char	t_uc;

static void				*aux_ft_memcpy(void *dst, const void *src, size_t n);
static void				*aux_ft_calloc(size_t nmemb, size_t size);
static size_t			aux_ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	s_len = (t_uint)aux_ft_strlen(s);
	if (start > s_len)
		return ((char *)aux_ft_calloc(1, sizeof(char)));
	else if (len > s_len - start)
	{
		substr = malloc((s_len - start + 1) * sizeof(char));
		aux_ft_memcpy(substr, s + start, s_len - start);
		substr[s_len - start] = '\0';
		return (substr);
	}
	else
	{
		substr = malloc((len + 1) * sizeof(char));
		aux_ft_memcpy(substr, s + start, len);
		substr[len] = '\0';
		return (substr);
	}
}

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

static inline size_t	aux_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline void	*aux_ft_calloc(size_t nmemb, size_t size)
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
