/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:08 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/03 02:50:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_strarray(char **strarray)
{
	int	i;

	i = 0;
	while (strarray[i] != NULL)
	{
		ft_printf("%s\n", strarray[i]);
		i++;
	}
}

void	print_intarray(int *intarray, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", intarray[i]);
		i++;
	}
}

int	ft_strarray_len(char **strarray)
{
	int	size;

	size = 0;
	while (strarray[size] != NULL)
	{
		size++;
	}
	return (size);
}

/**
 * @brief Allocates and returns a new string which is the result of the
 * concatenation of 's1', 'c', and 's2'.
 * @param s1 The first string. If NULL, it is treated as an empty string.
 * @param s2 The second string to append to 's1'. If NULL, it is treated as an
 * empty string.
 * @param c The character to insert between 's1' and 's2'.
 * @return A pointer to the newly allocated concatenated string, or NULL if
 * memory allocation fails.
 * @note The function uses malloc, so the caller is responsible for freeing the
 * returned string when it is no longer needed.
 */
char	*ft_strjoin_char(char const *s1, char const *s2, char c)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	joined[i] = c;
	i++;
	j = -1;
	while (++j < s2_len)
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	return (joined);
}

// typedef struct	s_node
// {
// 	int	nbr;
// 	int	pos;
// 	int	max_p;
// 	int	sort;
// }	t_node;

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
