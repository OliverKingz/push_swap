/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:49 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 22:13:12 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotation_count_tohead(t_dnode *stack, int index);
void		k_sort1(t_stack *a, t_stack *b, int size);
void		k_sort2(t_stack *a, t_stack *b, int size);

void	k_sort1(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	range;

	i = 0;
	range = my_sqrt(size) * 14 / 10;
	while (a->head != NULL)
	{
		if (a->head->value <= i)
		{
			exe_print_op(a, b, "pb");
			if (b->size > 1)
				exe_print_op(NULL, b, "rb");
			i++;
		}
		else if (a->head->value <= i + range)
		{
			exe_print_op(a, b, "pb");
			i++;
		}
		else
			exe_print_op(a, NULL, "ra");
	}
}

void	k_sort2(t_stack *a, t_stack *b, int size)
{
	int	rb_count;
	int	rrb_count;

	while (size - 1 >= 0)
	{
		rb_count = rotation_count_tohead(b->head, size - 1);
		rrb_count = b->size - rb_count;
		if (rb_count <= rrb_count)
		{
			while (b->head->value != size - 1)
				exe_print_op(NULL, b, "rb");
			exe_print_op(a, b, "pa");
			size--;
		}
		else
		{
			while (b->head->value != size - 1)
				exe_print_op(NULL, b, "rrb");
			exe_print_op(a, b, "pa");
			size--;
		}
	}
}

int	my_sqrt(int n)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (result <= n)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

static int	rotation_count_tohead(t_dnode *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->value == index)
			return (counter);
		stack = stack->next;
		counter++;
	}
	return (-1);
}

int	find_min_i(t_stack *stack)
{
	int		min_value;
	t_dnode	*current;
	int		min_index;
	int		i;

	if (stack == NULL || stack->head == NULL)
		return (ft_putstr_fd("Unable to find min index", 2), -1);
	min_value = stack->head->value;
	current = stack->head;
	min_index = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}
