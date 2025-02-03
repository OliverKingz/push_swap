/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:22:47 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 20:13:35 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a)
{
	if (a->size == 2)
		sort2(a);
	else if (a->size == 3)
		sort3(a);
	else if (a->size == 4)
		sort4(a);
	else if (a->size == 5)
		sort5(a);
}

void	sort2(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		exe_print_op(a, NULL, "sa");
}

// This function sorts a stack of size 3 in ascending order
// There are 6 possible cases to consider:
// - 1 2 3 (already sorted)
// - 1 3 2 (first case)
// - 2 1 3
// - 2 3 1
// - 3 1 2
// - 3 2 1 (last case)
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

void	sort4(t_stack *a)
{
	(void)a;
}

void	sort5(t_stack *a)
{
	(void)a;
}
