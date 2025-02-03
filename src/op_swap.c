/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:54:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 20:51:07 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swap the first two elements at the top of stack a if there are
 * at least two elements.
 *
 * @param a Pointer to stack a.
 */
void	sa(t_stack *a)
{
	t_dnode	*aux;

	if (a->size >= 2)
	{
		aux = a->head;
		a->head = a->head->next;
		aux->next = a->head->next;
		if (a->head->next != NULL)
			a->head->next->prev = aux;
		a->head->next = aux;
		a->head->prev = NULL;
		aux->prev = a->head;
	}
}

/**
 * @brief Swap the first two elements at the top of stack b if there are
 * at least two elements.
 *
 * @param b Pointer to stack b.
 */
void	sb(t_stack *b)
{
	t_dnode	*aux;

	if (b->size >= 2)
	{
		aux = b->head;
		b->head = b->head->next;
		aux->next = b->head->next;
		if (b->head->next != NULL)
			b->head->next->prev = aux;
		b->head->next = aux;
		b->head->prev = NULL;
		aux->prev = b->head;
	}
}

/**
 * @brief Perform switch_a and switch_b operations simultaneously.
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
