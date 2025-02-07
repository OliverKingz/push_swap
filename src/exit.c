/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:23:38 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 01:10:16 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	msg = NULL;
	if (msg)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	free_strarray(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i] != NULL)
	{
		free(strarray[i]);
		i++;
	}
	free(strarray);
}

void	free_stack(t_stack *stack)
{
	t_dnode	*current;
	t_dnode	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
