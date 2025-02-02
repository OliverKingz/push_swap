/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:23:38 by ozamora-          #+#    #+#             */
/*   Updated: 2025/02/02 20:19:09 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	free_strarray(char **strarray)
{
	int i = 0;
	while (strarray[i] != NULL)
	{
		free(strarray[i]);
		i++;
	}
	free(strarray);
}
