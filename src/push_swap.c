/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:01:48 by ozamora-          #+#    #+#             */
/*   Updated: 2024/12/05 16:48:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_node
{
	int	nbr;
	int	pos;
	int	max_p;
	int	sort;
}	t_node;

// void	one_argument(char *argv)
// {
// 	char **s_a;

// 	s_a = ft_split(argv, ' ');
// }

// void sort2()
// {

// }

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

void	free_str_array(char **strarray)
{
	int i = 0;
	while (strarray[i] != NULL)
	{
		free(strarray[i]);
		i++;
	}
	free(strarray);
}

int	main(int argc, char **argv)
{
	char **args;

	if (argc < 2)
		(ft_putstr_fd("Error: push_swap needs more arguments\n", 2), exit(1));
	args = ft_arg_to_strarray(argc, argv);
	if (!args || !arg_is_int(argc, args) || !arg_is_int_dup(argc, args))
	{
		free_str_array(args);
		exit(1);
	}
	else
		ft_printf("Everything okay\n");
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
