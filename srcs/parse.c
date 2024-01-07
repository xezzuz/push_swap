/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:39:52 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/07 14:00:46 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_extract_args(char **argv)
{
	char	*tmp;
	char	*str;
	char	**matrix;
	int		i;

	i = 1;
	// tmp = ft_strdup(" ");
	// if (!tmp)
	// 	return (NULL);
	tmp = NULL;
	while (argv[i])
	{
		str = ft_strjoin(tmp, argv[i]);
		if (!str)
			return (free (tmp), NULL);
		free (tmp);
		tmp = ft_strjoin(str, " ");
		if (!tmp)
			return (free (str), NULL);
		free (str);
		i++;
	}
	matrix = ft_split(tmp, 32);
	free (tmp);
	return (matrix);
}

int	*ft_matrix_to_int(char **matrix, int size)
{
	int				i;
	long long		num;
	int				*result;

	result = malloc (size * sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		num = ft_atoll(matrix[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (free (result), NULL);
		result[i] = num;
		i++;
	}
	if (!ft_check_duplicates(result, size))
		return (free(result), NULL);
	return (result);
}

int	*ft_parse_check(char **argv, int *length)
{
	char	**matrix;
	int		*seq;
	int		*lis;

	if (ft_is_blank(argv))
		ft_exit(0);
	matrix = ft_extract_args(argv);
	if (!matrix)
		ft_exit(0);
	ft_print_matrix(matrix);
	if (!ft_check_num(matrix))
	{
		// free (matrix);
		ft_exit(0);
	}
	*length = ft_matrix_size(matrix);
	printf("\n\n");
	printf("\n\n");
	seq = ft_matrix_to_int(matrix, *length);
	if (!seq)
	{
		// free (matrix);
		ft_exit(0);
	}
	if (*length == 1)
		ft_exit(1);
	ft_print_int(seq, *length);
	lis = ft_extract_lis(seq, *length);
	if (!lis)
		return (free(seq), NULL); // free matrix
	return (free(seq), lis); // free matrix
}
