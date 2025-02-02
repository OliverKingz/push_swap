/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 19:03:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char **args;

	if (argc < 2)
		(ft_putstr_fd("Usage: ./push_swap 42 -6 0*\n", 2), exit(1));
	args = ft_arg_to_strarray(argc, argv);
	// if (!args || !arg_is_int(argc, args) || !arg_is_int_dup(argc, args))
	// 	free_str_array(args), ft_err("Invalid arg");
	free_str_array(args);
	return (0);
}

/*
	ft_putstr_fd("Error: instrucction doesn't exist\n", 2);
	ft_putstr_fd("Error: incorrect format\n", 2);
*/

	// static t_node	**stack_a;
	// int				size_a;
	// size_a = argc - 1;
	// stack_a = (t_node **)malloc((size_a) * sizeof(t_node *));
	// if (!stack_a)
	// 	(ft_printf("Error: malloc"), exit(1));
	// init_stack(stack_a, size_a, argv);
	// ft_printf("Mas arguments\n");
