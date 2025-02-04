/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:59 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/04 16:08:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **args)
{
	t_stack	*stack;
	int		*args_int;
	int		i;

	args_int = ft_strarray_to_intarray(args);
	if (!args_int)
	{
		free_strarray(args);
		return (ft_err("Failed to convert args to int array"), NULL);
	}
	stack = init_stack();
	if (!stack)
	{
		(free_strarray(args), free(args_int));
		return (ft_err("Failed to init stack"), NULL);
	}
	i = ft_strarray_len(args) - 1;
	while (i >= 0)
	{
		push(stack, args_int[i]);
		i--;
	}
	free(args_int);
	free_strarray(args);
	return (stack);
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_dnode	*init_dnode(int value)
{
	t_dnode	*new_dnode;

	new_dnode = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!new_dnode)
		return (NULL);
	new_dnode->value = value;
	new_dnode->prev = NULL;
	new_dnode->next = NULL;
	return (new_dnode);
}
