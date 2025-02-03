/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:33:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 20:34:07 by ozamora-         ###   ########.fr       */
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
		return (free_stack(stack), ft_err("Stack is empty"), -1);
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
		sa(a);
	else if (ft_strcmp(operation, "sb") == 0)
		sb(b);
	else if (ft_strcmp(operation, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(operation, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(operation, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(operation, "ra") == 0)
		ra(a);
	else if (ft_strcmp(operation, "rb") == 0)
		rb(b);
	else if (ft_strcmp(operation, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(operation, "rra") == 0)
		rra(a);
	else if (ft_strcmp(operation, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(operation, "rrr") == 0)
		rrr(a, b);
	else
		ft_err("Unkown operation");
}

void	exe_print_op(t_stack *a, t_stack *b, const char *operation)
{
	exe_op(a, b, operation);
	ft_printf("%s\n", operation);
}
