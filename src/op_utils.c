/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:33:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/06 15:17:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_dnode	*new;

	new = init_dnode(value);
	if (!new)
	{
		free_stack(stack);
		ft_err("Failed to initialize the node");
		return ;
	}
	new->next = stack->head;
	if (stack->size == 0)
	{
		stack->tail = new;
		stack->head = new;
	}
	else
	{
		stack->head->prev = new;
		stack->head = new;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_dnode	*node_to_remove;
	int		value;

	if (stack->size == 0)
		return (free_stack(stack), ft_err("Stack is empty in pop"), -1);
	node_to_remove = stack->head;
	value = node_to_remove->value;
	stack->head = node_to_remove->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	free(node_to_remove);
	stack->size--;
	return (value);
}

void	exe_op(t_stack *a, t_stack *b, const char *operation)
{
	if (ft_strcmp(operation, "sa") == 0)
		switch_a(a);
	else if (ft_strcmp(operation, "sb") == 0)
		switch_b(b);
	else if (ft_strcmp(operation, "ss") == 0)
		switch_both(a, b);
	else if (ft_strcmp(operation, "pa") == 0)
		push_bhead_toa(a, b);
	else if (ft_strcmp(operation, "pb") == 0)
		push_ahead_tob(a, b);
	else if (ft_strcmp(operation, "ra") == 0)
		rotate_up_a(a);
	else if (ft_strcmp(operation, "rb") == 0)
		rotate_up_b(b);
	else if (ft_strcmp(operation, "rr") == 0)
		rotate_up_both(a, b);
	else if (ft_strcmp(operation, "rra") == 0)
		rotate_down_a(a);
	else if (ft_strcmp(operation, "rrb") == 0)
		rotate_down_b(b);
	else if (ft_strcmp(operation, "rrr") == 0)
		rotate_down_both(a, b);
	else
		ft_err("Unkown operation");
}

//print_stack(stack_a, 'a');
//print_stack(stack_b, 'b');
void	exe_print_op(t_stack *a, t_stack *b, const char *operation)
{
	exe_op(a, b, operation);
	ft_printf("%s\n", operation);
}
