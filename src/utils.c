/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 20:00:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_strarray(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i] != NULL)
	{
		ft_printf("%s\n", strarray[i]);
		i++;
	}
}

void	print_intarray(int *intarray, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", intarray[i]);
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_dnode	*current;

	current = stack->head;
	if (stack->size == 0)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

int	ft_strarray_len(char **strarray)
{
	int	size;

	size = 0;
	while (strarray[size] != NULL)
	{
		size++;
	}
	return (size);
}
