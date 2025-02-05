/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 16:22:39 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts all the elements of the stack a up by one position.
 *
 * The first element becomes the last.
 *
 * @param a The stack to rotate.
 */
void	rotate_up_a(t_stack *a)
{
	t_dnode	*new_tail;
	t_dnode	*new_head;

	if (a->size > 1)
	{
		new_tail = a->head;
		new_head = a->head->next;
		new_head->prev = NULL;
		a->head = new_head;
		a->tail->next = new_tail;
		new_tail->prev = a->tail;
		new_tail->next = NULL;
		a->tail = new_tail;
	}
}

/**
 * @brief Shifts all the elements of the stack b up by one position.
 *
 * The first element becomes the last.
 *
 * @param b The stack to rotate.
 */
void	rotate_up_b(t_stack *b)
{
	t_dnode	*new_tail;
	t_dnode	*new_head;

	if (b->size > 1)
	{
		new_tail = b->head;
		new_head = b->head->next;
		new_head->prev = NULL;
		b->head = new_head;
		b->tail->next = new_tail;
		new_tail->prev = b->tail;
		new_tail->next = NULL;
		b->tail = new_tail;
	}
}

/**
 * @brief Performs ra and rotate_up_b at the same time.
 *
 * Shifts all the elements of both stacks up by one position.
 *
 * @param a The first stack to rotate.
 * @param b The second stack to rotate.
 */
void	rotate_up_both(t_stack *a, t_stack *b)
{
	rotate_up_a(a);
	rotate_up_b(b);
}
