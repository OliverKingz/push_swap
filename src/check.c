/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:22:44 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 18:24:10 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_is_int(int argc, char **args)
{
	int i;

	if (argc <= 1 || args == NULL)
		return (ft_putstr_fd("Error: no arg provided\n", 2), 0);
	i = 0;
	while (i < argc - 1)
	{
		if (!ft_issigned_nbr(args[i]))
			return (ft_putstr_fd("Error: arg is not a number\n", 2), 0);
		i++;
	}
	return (1);
}

int	arg_is_int_dup(int argc, char **args)
{
	int i;
	int j;
	int *args_int;

	if (argc <= 1 || args == NULL)
		return (ft_putstr_fd("Error: no arg provided\n", 2), 0);
	args_int = ft_strarray_to_intarray(args);
	if (args_int == NULL)
		return (ft_putstr_fd("Error: memory allocation failed\n", 2), 0);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (args_int[j] < argc - 1)
		{
			if (args_int[i] == args_int[j])
			{
				free(args_int);
				ft_putstr_fd("Error: arg is duplicated\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(args_int);
	return (1);
}