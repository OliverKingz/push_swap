/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 18:25:01 by ozamora-         ###   ########.fr       */
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
