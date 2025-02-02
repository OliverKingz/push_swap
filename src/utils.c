/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 18:43:09 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_strarray(char **strarray)
{
	int i = 0;
	while (strarray[i] != NULL)
	{
		ft_printf("%s\n", strarray[i]);
		i++;
	}
}

// typedef struct	s_node
// {
// 	int	nbr;
// 	int	pos;
// 	int	max_p;
// 	int	sort;
// }	t_node;


/* void	init_stack(t_node **stack, int size, char **argv)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = (t_node *)malloc(sizeof(t_node));
		if (!stack[i])
			(ft_printf("Error: malloc"), free_stack(stack, size), exit(1));
		init_node(stack[i], argv[i + 1]);
		i++;
	}
}

void	init_node(t_node *node, char *argv)
{
	node->nbr = 0;
	node->pos = 0;
	node->sort = 0;
	node->max_p = 0;
}
 */
