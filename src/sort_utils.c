/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:57:35 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 20:27:58 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
