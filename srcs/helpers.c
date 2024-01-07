/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:06:40 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/06 19:04:15 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		printf("matrix[%d] = %s\n", i, matrix[i]);
		i++;
	}
}

void	ft_print_int(int *array, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		printf("[%d]", array[i]);
		i++;
	}
}