/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:29 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 02:48:45 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from stack b to stack a.
 *
 * If stack b is not empty, this function takes the first element on top of b
 * and puts it on top of stack a.
 *
 * @param a The destination stack.
 * @param b The source stack.
 */
void	pa(t_stack *a, t_stack *b);

/**
 * @brief Pushes the top element from stack a to stack b.
 *
 * If stack a is not empty, this function takes the first element on top of
 * stack a and puts it on top of stack b.
 *
 * @param a The source stack.
 * @param b The destination stack.
 */
void	pb(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b)
{
	if (b->size != 0)
	{
		push(a, pop(b));
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size != 0)
	{
		push(b, pop(a));
	}
}
