/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:13:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/07 12:43:55 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_init_arr(int **length, int **sub_seq, int n)
{
	int		i;

	i = 0;
	*length = malloc (n * sizeof(int));
	if (!*length)
		return (0);
	*sub_seq = malloc (n * sizeof(int));
	if (!*sub_seq)
		return (free(*length), 0);
	while (i < n)
	{
		(*length)[i] = 1;
		(*sub_seq)[i++] = -1;
	}
	return (1);
}

int	ft_get_max_len(int *length, int n)
{
	int		i;
	int		max;

	max = 0;
	i = 1;
	while (i < n)
	{
		if (length[i] > length[max])
			max = i;
		i++;
	}
	return (max);
}

int	ft_sub_seq(int **seq, int **length, int **sub_seq, int n)
{
	int		i;
	int		j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if ((*seq)[j] < (*seq)[i] && (*length)[i] <= (*length)[j] + 1)
			{
				(*length)[i] = (*length)[j] + 1;
				(*sub_seq)[i] = j;
			}
			j++;
		}
		i++;
	}
	return (ft_get_max_len(*length, n));
}

int	*ft_extract_lis(int *seq, int n)
{
	int		i;
	int		lis_len;
	int		max_len_indx;
	int		curr_indx;
	int		*length;
	int		*sub_seq;
	int		*lis;

	if (!ft_init_arr(&length, &sub_seq, n))
		return (NULL);
	max_len_indx = ft_sub_seq(&seq, &length, &sub_seq, n);
	lis_len = length[max_len_indx];
	lis = malloc (lis_len * sizeof(int));
	if (!lis)
		return (NULL);
	i = lis_len - 1;
	curr_indx = max_len_indx;
	while (curr_indx != -1)
	{
		lis[i--] = seq[curr_indx];
		curr_indx = sub_seq[curr_indx];
	}
	// printf("\n\nlength:");
	// ft_print_int(length, n);
	// printf("\n\nsubseq:");
	// ft_print_int(sub_seq, n);
	// printf("\nfinal\n");
	// printf("max_length = %d", lis_len);
	// printf("\nmax_len_indx = %d\n\nLIS: ", max_len_indx);
	// ft_print_int(lis, lis_len);
	return (free(length), free(sub_seq), lis);
}