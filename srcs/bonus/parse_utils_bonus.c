/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:06:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 16:58:52 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	ft_free_matrix(char ***matrix)
{
	int		i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while ((*matrix)[i])
	{
		free ((*matrix)[i]);
		i++;
	}
	free (*matrix);
}

int	ft_is_blank(char **argv)
{
	int		i;
	int		j;
	int		blank;

	blank = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		blank = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '\t' && argv[i][j] != ' ')
				blank++;
			j++;
		}
		if (blank == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_matrix_size(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	ft_check_num(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		if (matrix[i][j] == '+' || matrix[i][j] == '-')
			j++;
		if (!matrix[i][j])
			return (0);
		while (matrix[i][j])
		{
			if (matrix[i][j] < '0' || matrix[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicates(int *array, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
