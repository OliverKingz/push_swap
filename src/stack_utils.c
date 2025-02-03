/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:33:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 02:49:39 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_dnode	*new;

	new = init_dnode(value);
	if (!new)
		ft_err("Failed to initialize the node");
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
		return (ft_err("Stack is empty"), -1);
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
