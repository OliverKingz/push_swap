/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:40 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 16:23:56 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts all elements of the stack a down one position.
 *
 * The last element becomes the first.
 *
 * @param a The stack to reverse rotate.
 */
void	rotate_down_a(t_stack *a)
{
	t_dnode	*new_head;
	t_dnode	*new_tail;

	if (a->size > 1)
	{
		new_head = a->tail;
		new_tail = a->tail->prev;
		new_tail->next = NULL;
		a->tail = new_tail;
		new_head->prev = NULL;
		new_head->next = a->head;
		a->head->prev = new_head;
		a->head = new_head;
	}
}

/**
 * @brief Shifts all the elements of the stack b down one position.
 *
 * The last element becomes the first.
 *
 * @param b The stack to reverse rotate.
 */
void	rotate_down_b(t_stack *b)
{
	t_dnode	*new_head;
	t_dnode	*new_tail;

	if (b->size > 1)
	{
		new_head = b->tail;
		new_tail = b->tail->prev;
		new_tail->next = NULL;
		b->tail = new_tail;
		new_head->prev = NULL;
		new_head->next = b->head;
		b->head->prev = new_head;
		b->head = new_head;
	}
}

/**
 * @brief Performs rotate_down_a and rotate_down_b at the same time.
 *
 * Shifts all elements of both stacks down one position.
 *
 * @param a The first stack to reverse rotate.
 * @param b The second stack to reverse rotate.
 */
void	rotate_down_both(t_stack *a, t_stack *b)
{
	rotate_down_a(a);
	rotate_down_b(b);
}
