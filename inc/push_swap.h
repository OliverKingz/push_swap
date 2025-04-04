/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/04/02 12:49:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
Explicitly allowed functions for push_swap, already included at the library
# include <stdlib.h>  // To use memory allocation (malloc, free) and exit
# include <unistd.h>  // To use system calls like read and write

Functions used from libft:
- ft_atol
- ft_issigned_nbr
- ft_strdup
- ft_strjoin_char
- ft_strncmp
- ft_split
- ft_calloc
- ft_printf
- ft_putstr_fd
*/

typedef struct s_dnode
{
	int				value;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}					t_dnode;

typedef struct s_stack
{
	t_dnode			*head;
	t_dnode			*tail;
	int				size;
}					t_stack;

void				push_swap_usage(void);

char				**my_arg_to_strarray(int argc, char **argv);
int					*my_strarray_to_intarray(char **str);

int					check_args_int(char **args);
int					check_args_dup(char **args);
int					check_stack_sorted(t_stack *a);

t_stack				*create_stack(char **args);
t_stack				*init_stack(void);
t_dnode				*init_dnode(int value);

int					*index_intarray(int *array, int size);
void				my_qsort_intarray(int *arr, size_t size);

void				sort(t_stack *a, t_stack *b);
void				sort2(t_stack *a);
void				sort3(t_stack *a);
void				sort4(t_stack *a, t_stack *b);
void				sort5(t_stack *a, t_stack *b);

void				k_sort1(t_stack *a, t_stack *b, int size);
void				k_sort2(t_stack *a, t_stack *b, int size);
int					find_min_i(t_stack *stack);

void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				exe_op(t_stack *a, t_stack *b, char *operation);
void				exe_print_op(t_stack *a, t_stack *b, char *operation);

void				switch_a(t_stack *a);
void				switch_b(t_stack *b);
void				switch_both(t_stack *a, t_stack *b);

void				push_bhead_toa(t_stack *a, t_stack *b);
void				push_ahead_tob(t_stack *a, t_stack *b);

void				rotate_up_a(t_stack *a);
void				rotate_up_b(t_stack *b);
void				rotate_up_both(t_stack *a, t_stack *b);

void				rotate_down_a(t_stack *a);
void				rotate_down_b(t_stack *b);
void				rotate_down_both(t_stack *a, t_stack *b);

void				my_err(const char *msg);
void				free_strarray(char **strarray);
void				free_stack(t_stack *stack);
void				free_stacks(t_stack *a, t_stack *b);

void				print_strarray(char **strarray);
void				print_intarray(int *intarray, int size);
void				print_stack(t_stack *stack, char stack_name);
int					my_strarray_len(char **strarray);
int					my_str_num_len(char *str_num);

#endif