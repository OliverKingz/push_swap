/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:33:55 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/09 14:37:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Computes the length of a string.
 * @param s The string to measure.
 * @return The number of characters in the string, excluding the null terminator.
 * @note If `str` is NULL, the behavior is undefined.
 */
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return ((size_t)len);
}
