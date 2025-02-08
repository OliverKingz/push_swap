/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:17:19 by ozamora-          #+#    #+#             */
/*   Updated: 2024/12/03 16:52:06 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given string is a signed number.
 * @param str The string to check
 * @return 
 * - 1 if the string is a signed number.
 * 
 * - 0 if the string is NOT a signed number
 */
int	ft_issigned_nbr(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
