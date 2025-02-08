/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/08 16:48:21 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		my_err("");
	args = my_arg_to_strarray(argc, argv);
	if (!args || !check_args_int(args) || !check_args_dup(args))
		return (free_strarray(args), my_err("Invalid arg: dup or not int"), 1);
	stack_a = create_stack(args);
	stack_b = init_stack();
	if (check_stack_sorted(stack_a) == 1 && stack_b->size == 0)
		return (free_stacks(stack_a, stack_b), 0);
	sort(stack_a, stack_b);
	if (check_stack_sorted(stack_a) == 1 && stack_b->size == 0)
		return (free_stacks(stack_a, stack_b), 0);
	else
		return (free_stacks(stack_a, stack_b), ft_putstr_fd("KO\n", 2), 1);
	return (free_stacks(stack_a, stack_b), 0);
}
