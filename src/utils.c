/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/05 16:14:12 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_strarray(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i] != NULL)
	{
		ft_printf("%s ", strarray[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_intarray(int *intarray, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", intarray[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack(t_stack *stack, char stack_name)
{
	t_dnode	*current;

	current = stack->head;
	ft_printf("%c: ", stack_name);
	if (stack->size == 0)
	{
		ft_printf("printing empty stack\n");
		return ;
	}
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
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

int	ft_str_num_len(char *str_num)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str_num[i] == '-' || str_num[i] == '+')
	{
		i++;
	}
	while (str_num[i] == '0')
	{
		i++;
	}
	while (str_num[i] >= '0' && str_num[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}
