/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:22:44 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 21:03:15 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_int(char **args)
{
	int	i;

	if (args == NULL || *args == NULL)
		return (0);
	i = 0;
	while (args[i] != NULL)
	{
		if (!ft_issigned_nbr(args[i]))
			return (free_strarray(args), ft_err("Arg is not valid number"), 0);
		i++;
	}
	return (1);
}

int	check_args_dup(char **args)
{
	int i;
	int j;
	int *args_int;
	int	arg_len;

	if (args == NULL || *args == NULL)
		return (0);
	args_int = ft_strarray_to_intarray(args);
	if (args_int == NULL)
		return (ft_err("Failed to malloc"), 0);
	arg_len = ft_strarray_len(args);
	i = 0;
	while (i < arg_len)
	{
		j = i + 1;
		while (j < arg_len)
		{
			if (args_int[i] == args_int[j])
				return (free(args_int), ft_err("Arg is duplicated"), 0);
			j++;
		}
		i++;
	}
	free(args_int);
	return (1);
}
