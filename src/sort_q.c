/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_q.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:50 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 22:13:19 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*index_intarray(int *args_int, int size);
void		my_qsort_intarray(int *arr, size_t size);
static void	ft_qsort_recursive(int *arr, int low, int high);
static int	partition(int *arr, int low, int high);
static void	ft_swap(int *a, int *b);

int	*index_intarray(int *args_int, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = (int *)ft_calloc(1, size * sizeof(int));
	if (!sorted)
		return (free(args_int), my_err("Failed malloc for sorted array"), NULL);
	i = -1;
	while (++i < size)
		sorted[i] = args_int[i];
	my_qsort_intarray(sorted, size);
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

void	my_qsort_intarray(int *arr, size_t size)
{
	if (size > 1)
		ft_qsort_recursive(arr, 0, size - 1);
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	ft_qsort_recursive(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		ft_qsort_recursive(arr, low, pi - 1);
		ft_qsort_recursive(arr, pi + 1, high);
	}
}
