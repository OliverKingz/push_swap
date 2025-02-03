/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 19:15:32 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;

	if (argc < 2)
		(ft_putstr_fd("Usage: ./push_swap 42 -6 0\n", 2), exit(1));
	args = ft_arg_to_strarray(argc, argv);
	if (!args || !check_args_int(args) || !check_args_dup(args))
		return (free_strarray(args), ft_err("Invalid arg"), 1);
	stack_a = create_stack(args);
	print_stack(stack_a);
	if (check_stack_sorted(stack_a) == 1)
		return (free_stack(stack_a), ft_err("Arg are already sorted"), 1);
	sort(stack_a);
	print_stack(stack_a);
	if (!check_stack_sorted(stack_a))
		return (free_stack(stack_a), ft_err("Failed to sort"), 1);
	free_stack(stack_a);
	return (0);
}

// }
// int	main(int argc, char **argv)
// {
// 	char	**args;
// 	int		*args_int;

// 	if (argc < 2)
// 		(ft_putstr_fd("Usage: ./push_swap 42 -6 0\n", 2), exit(1));
// 	args = ft_arg_to_strarray(argc, argv);
// 	print_strarray(args);
// 	if (!args || !check_args_int(args) || !check_args_dup(args))
// 		return (free_strarray(args), ft_err("Invalid arg"), 1);
// 	args_int = ft_strarray_to_intarray(args);
// 	print_intarray(args_int, ft_strarray_len(args));
// 	(free_strarray(args), free(args_int));
// 	return (0);
// }
