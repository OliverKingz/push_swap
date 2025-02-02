/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:50 by ozamora-         ###   ########.fr       */
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

int		*ft_strarray_to_intarray(char **str);
long	*ft_strarray_to_longarray(char **str);
int		ft_str_wordcounter(char const *s, char c);
char	**ft_arg_to_strarray(int argc, char **argv);

int		arg_is_int(int argc, char **args);
int		arg_is_int_dup(int argc, char **args);

void	ft_err(const char *msg);
void	free_str_array(char **strarray);

#endif