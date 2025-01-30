/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:39:08 by ozamora-          #+#    #+#             */
/*   Updated: 2024/12/11 18:11:41 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_is_int(int argc, char **args)
{
	int i;

	if (argc <= 1 || args == NULL)
		return (ft_putstr_fd("Error: no arg provided\n", 2), 0);
	i = 0;
	while (i < argc - 1)
	{
		if (!ft_issigned_nbr(args[i]))
			return (ft_putstr_fd("Error: arg is not a number\n", 2), 0);
		i++;
	}
	return (1);
}

int	arg_is_int_dup(int argc, char **args)
{
	int i;
	int j;
	int *args_int;

	if (argc <= 1 || args == NULL)
		return (ft_putstr_fd("Error: no arg provided\n", 2), 0);
	args_int = ft_strarray_to_intarray(args);
	if (args_int == NULL)
		return (ft_putstr_fd("Error: memory allocation failed\n", 2), 0);
	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (args_int[j] < argc - 1)
		{
			if (args_int[i] == args_int[j])
			{
				free(args_int);
				ft_putstr_fd("Error: arg is duplicated\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(args_int);
	return (1);
}

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
	int		i;

	if (argc == 2)
	{
		if (ft_str_wordcounter(argv[1], ' ') > 1)
			str_array = ft_split(argv[1], ' ');
		else
			(ft_putstr_fd("Error: need more arg\n", 2), exit(1));
	}
	else
	{
		str_array = (char **)malloc((argc - 1) * sizeof(char *));
		if (!str_array)
			(ft_putstr_fd("Error: malloc\n", 2), exit(1));
		i = 0;
		while (i < argc - 1)
		{
			str_array[i] = ft_strdup(argv[i + 1]);
			if (!str_array[i])
				(ft_putstr_fd("Error: malloc\n", 2), exit(1));
			i++;
		}
	}
	return (str_array);
}
