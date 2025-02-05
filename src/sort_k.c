/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:49 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 17:36:11 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_sort1(t_stack *a, t_stack *b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (a->head != NULL)
	{
		if (a->head->value <= i)
		{
			exe_print_op(a, b, "pb");
			if (b->size > 1)
				exe_print_op(NULL, b, "rb"); // Solo si hay más de un elemento en B
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

void	k_sort2(t_stack *a, t_stack *b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = rotation_count_tohead(b->head, length - 1);
		rrb_count = b->size - rb_count; //Correcction
		//rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (b->head->value != length - 1)
				exe_print_op(NULL, b, "rb");
			exe_print_op(a, b, "pa");
			length--;
		}
		else
		{
			while (b->head->value != length - 1)
				exe_print_op(NULL, b, "rrb");
			exe_print_op(a, b, "pa");
			length--;
		}
	}
}

int	ft_sqrt(int n)
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

int	rotation_count_tohead(t_dnode *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack) 
	{
		if (stack->value == index)
			return counter;
		stack = stack->next;
		counter++;
	}
	return (-1); // Retornar -1 si no se encuentra
}
