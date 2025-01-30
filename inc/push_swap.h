/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:14 by ozamora-          #+#    #+#             */
/*   Updated: 2024/12/05 15:13:33 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int		*ft_strarray_to_intarray(char **str);
long	*ft_strarray_to_longarray(char **str);
int		ft_str_wordcounter(char const *s, char c);
char	**ft_arg_to_strarray(int argc, char **argv);
int		arg_is_int(int argc, char **args);
int		arg_is_int_dup(int argc, char **args);

#endif