/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:22:47 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 17:26:33 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else
	{
		k_sort1(a, b, size);
		k_sort2(a, b, size);
	}
}

void	sort2(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		exe_print_op(a, NULL, "sa");
}

/**
 * @brief Sorts a stack of size 3 in ascending order.
 * @param a The stack to be sorted.
 * @note There are 6 possible cases to consider:
 * 
 * - 1 2 3 (already sorted)

 * - 1 3 2 (first case)
 * 
 * - 2 1 3
 * 
 * - 2 3 1
 * 
 * - 3 1 2
 * 
 * - 3 2 1 (last case)
 */
void	sort3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first < second && second > third && first < third)
	{
		exe_print_op(a, NULL, "sa");
		exe_print_op(a, NULL, "ra");
	}
	else if (first > second && second < third && first < third)
		exe_print_op(a, NULL, "sa");
	else if (first < second && second > third && first > third)
		exe_print_op(a, NULL, "rra");
	else if (first > second && second < third && first > third)
		exe_print_op(a, NULL, "ra");
	else if (first > second && second > third && first > third)
	{
		exe_print_op(a, NULL, "sa");
		exe_print_op(a, NULL, "rra");
	}
}

void	sort4(t_stack *a, t_stack *b)
{
	while (find_min_index(a) != 0)
	{
		if (find_min_index(a) <= 2)
			exe_print_op(a, NULL, "ra");
		else
			exe_print_op(a, NULL, "rra");
	}
	exe_print_op(a, b, "pb");
	sort3(a);
	exe_print_op(a, b, "pa");
}

void	sort5(t_stack *a, t_stack *b)
{
	while (find_min_index(a) != 0)
	{
		if (find_min_index(a) <= 2)
			exe_print_op(a, NULL, "ra");
		else
			exe_print_op(a, NULL, "rra");
	}
	exe_print_op(a, b, "pb");
	while (find_min_index(a) != 0)
	{
		if (find_min_index(a) <= 2)
			exe_print_op(a, NULL, "ra");
		else
			exe_print_op(a, NULL, "rra");
	}
	exe_print_op(a, b, "pb");
	sort3(a);
	exe_print_op(a, b, "pa");
	exe_print_op(a, b, "pa");
}
