/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:33:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 18:33:02 by ozamora-         ###   ########.fr       */
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

void	exe_op(t_stack *a, t_stack *b, char *op)
{
	if (!(ft_strncmp(op, "sa", 2)) || !(ft_strncmp(op, "sa\n", 3)))
		switch_a(a);
	else if (!(ft_strncmp(op, "sb", 2)) || !(ft_strncmp(op, "sb\n", 3)))
		switch_b(b);
	else if (!(ft_strncmp(op, "ss", 2)) || !(ft_strncmp(op, "ss\n", 3)))
		switch_both(a, b);
	else if (!(ft_strncmp(op, "pa", 2)) || !(ft_strncmp(op, "pa\n", 3)))
		push_bhead_toa(a, b);
	else if (!(ft_strncmp(op, "pb", 2)) || !(ft_strncmp(op, "pb\n", 3)))
		push_ahead_tob(a, b);
	else if (!(ft_strncmp(op, "rra", 3)) || !(ft_strncmp(op, "rra\n", 4)))
		rotate_down_a(a);
	else if (!(ft_strncmp(op, "rrb", 3)) || !(ft_strncmp(op, "rrb\n", 4)))
		rotate_down_b(b);
	else if (!(ft_strncmp(op, "rrr", 3)) || !(ft_strncmp(op, "rrr\n", 4)))
		rotate_down_both(a, b);
	else if (!(ft_strncmp(op, "ra", 2)) || !(ft_strncmp(op, "ra\n", 3)))
		rotate_up_a(a);
	else if (!(ft_strncmp(op, "rb", 2)) || !(ft_strncmp(op, "rb\n", 3)))
		rotate_up_b(b);
	else if (!(ft_strncmp(op, "rr", 2)) || !(ft_strncmp(op, "rr\n", 3)))
		rotate_up_both(a, b);
	else
		(free(op), free_stacks(a, b), ft_err("Unkown operation"));
}

//print_stack(stack_a, 'a');
//print_stack(stack_b, 'b');
void	exe_print_op(t_stack *a, t_stack *b, char *operation)
{
	exe_op(a, b, operation);
	ft_printf("%s\n", operation);
}
