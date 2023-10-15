/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randomize_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:52:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/07 15:11:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_randomize_array(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	temp;

	srand(time(NULL));
	i = arr_size - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i--;
	}
}
