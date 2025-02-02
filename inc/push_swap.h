/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 20:58:48 by ozamora-         ###   ########.fr       */
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

char	**ft_arg_to_strarray(int argc, char **argv);
int		*ft_strarray_to_intarray(char **str);
long	*ft_strarray_to_longarray(char **str);

int		check_args_int(char **args);
int		check_args_dup(char **args);

void	ft_err(const char *msg);
void	free_strarray(char **strarray);

void	print_strarray(char **strarray);
void	print_intarray(int *intarray, int size);
int		ft_strarray_len(char **strarray);
char	*ft_strjoin_char(char const *s1, char const *s2, char c);

#endif