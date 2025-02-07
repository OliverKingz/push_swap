/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:39:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/07 22:15:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**my_arg_to_strarray(int argc, char **argv)
{
	char	**str_array;
	char	*str;
	char	*aux;
	int		i;

	if (argc < 2)
		return (NULL);
	str = ft_strdup("");
	if (!str)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '\0')
			return (free(str), NULL);
		aux = str;
		str = ft_strjoin_char(aux, argv[i], ' ');
		if (!str)
			return (free(aux), aux = NULL, NULL);
		free(aux);
	}
	str_array = ft_split(str, ' ');
	if (!str_array)
		return (free(str), str = NULL, NULL);
	return (free(str), str_array);
}

int	*my_strarray_to_intarray(char **str)
{
	int		num_strs;
	int		i;
	int		*int_array;
	long	value;

	if (str == NULL || *str == NULL)
		return (NULL);
	num_strs = 0;
	while (str[num_strs] != NULL)
		num_strs++;
	int_array = (int *)ft_calloc(num_strs, sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (i < num_strs)
	{
		value = ft_atol(str[i]);
		if (value > INT_MAX || value < INT_MIN || my_str_num_len(str[i]) > 10)
			return (free(int_array), NULL);
		int_array[i] = (int)value;
		i++;
	}
	return (int_array);
}
