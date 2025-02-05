/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:50 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 20:47:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	*index_intarray(int *args_int, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = (int *)ft_calloc(1, size * sizeof(int));
	if (!sorted)
		return (free(args_int), ft_err("Failed malloc for sorted array"), NULL);
	i = -1;
	while (++i < size)
		sorted[i] = args_int[i];
	qsort(sorted, size, sizeof(int), compare);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (args_int[i] == sorted[j])
			{
				args_int[i] = j;
				break ;
			}
		}
	}
	return (free(sorted), args_int);
}
