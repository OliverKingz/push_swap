/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:39:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 18:32:22 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_strarray_to_intarray(char **str)
{
	int		size;
	int		i;
	int		*int_array;
	long	value;

	if (str == NULL || *str == NULL)
		return NULL;
	size = 0;
	while (str[size] != NULL)
		size++;
	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		return (ft_putstr_fd("Error: malloc\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		value = ft_atol(str[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_putstr_fd("Error: int overflow/underflow\n", 2);
			free(int_array);
			return NULL;
		}
		int_array[i] = (int) value;
		i++;
	}
	return int_array;
}

long	*ft_strarray_to_longarray(char **str)
{
	int		size;
	int		i;
	long	*long_array;

	size = 0;
	while (str[size] != NULL)
		size++;
	long_array = (long *)malloc(size * sizeof(long));
	if (!long_array)
		return (ft_putstr_fd("Error: malloc\n", 2), NULL);
	i = 0;
	while (i < size)
	{
		long_array[i] = ft_atol(str[i]);
		i++;
	}
	return (long_array);
}

int	ft_str_wordcounter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_arg_to_strarray(int argc, char **argv)
{
	char	**str_array;
	char	*str;
	char	*aux;
	int		i;

	if (argc < 2)
		return (NULL);
	str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		aux = str;
		str = ft_strjoin(aux, argv[i]);
		free(aux);
		i++;
	}
	str_array = ft_split(str, ' ');
	free(str);
	return (str_array);
}
