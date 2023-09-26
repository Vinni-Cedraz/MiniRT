/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:46:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/07 21:04:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			converted_len(size_t n, char *base);
static void				*aux_calloc(size_t nmemb, size_t size);
static size_t			aux_strlen(const char *str);

char	*ft_itoa_base(size_t n, char *base)
{
	int		len;
	int		baselen;
	char	*str;

	len = converted_len(n, base);
	baselen = aux_strlen(base);
	str = aux_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = base[n % baselen];
		n /= baselen;
	}
	return (str);
}

static size_t	converted_len(size_t n, char *base)
{
	t_ools	nb;

	nb.len = 1;
	nb.baselen = aux_strlen(base);
	while (n >= nb.baselen)
	{
		n /= nb.baselen;
		nb.len++;
	}
	return (nb.len);
}

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
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
