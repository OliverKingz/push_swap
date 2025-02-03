/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 02:54:29 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
Explicitly allowed functions for push_swap, already included at the library
# include <stdlib.h>  // To use memory allocation (malloc, free) and exit
# include <unistd.h>  // To use system calls like read and write
*/

/*
Functions used from libft:
- ft_atol
- ft_strdup
- ft_strjoin_char
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

t_stack				*create_stack(char **args);
t_stack				*init_stack(void);
t_dnode				*init_dnode(int value);
void				free_stack(t_stack *stack);
void				print_stack(t_stack *stack);

void				push(t_stack *stack, int value);
int					pop(t_stack *stack);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

char				**ft_arg_to_strarray(int argc, char **argv);
int					*ft_strarray_to_intarray(char **str);
long				*ft_strarray_to_longarray(char **str);

int					check_args_int(char **args);
int					check_args_dup(char **args);

void				ft_err(const char *msg);
void				free_strarray(char **strarray);

void				print_strarray(char **strarray);
void				print_intarray(int *intarray, int size);
int					ft_strarray_len(char **strarray);
char				*ft_strjoin_char(char const *s1, char const *s2, char c);

#endif