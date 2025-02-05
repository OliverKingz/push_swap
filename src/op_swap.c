/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 18:01:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first two elements at the top of stack a if there are
 * at least two elements.
 *
 * @param a Pointer to stack a.
 */
void	switch_a(t_stack *a)
{
	t_dnode	*first;
	t_dnode	*second;

	if (a->size < 2)
		return ;
	first = a->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	a->head = second;
	if (a->size == 2)
		a->tail = first;
}

/**
 * @brief Swap the first two elements at the top of stack b if there are
 * at least two elements.
 *
 * @param b Pointer to stack b.
 */
void	switch_b(t_stack *b)
{
	t_dnode	*first;
	t_dnode	*second;

	if (b->size < 2)
		return ;
	first = b->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	b->head = second;
	if (b->size == 2)
		b->tail = first;
}

/**
 * @brief Perform switch_a and switch_b operations simultaneously.
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	switch_both(t_stack *a, t_stack *b)
{
	switch_a(a);
	switch_b(b);
}
