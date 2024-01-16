/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/15 17:03:58 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit(int x)
{
	if (x == 0)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_parse_and_stock(char **argv, t_list_ex *a, t_arrays *arr)
{
	arr->seq = ft_parse_check(argv, arr);
	if (!arr->seq)
		return (0);
	if (!arr->seq_len)
	{
		free(arr->seq);
		ft_exit(1);
	}
	ft_stack_init(a, &arr->seq, arr->seq_len);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list_ex	a;
	t_list_ex	b;
	t_arrays	arr;

	a.head = NULL;
	b.head = NULL;
	if (argc == 1)
		return (0);
	if (!ft_parse_and_stock(argv, &a, &arr))
		ft_exit(0);
	if (!ft_is_sorted(&a))
	{
		if (a.size == 2)
			sa(&a);
		else if (a.size == 3)
			ft_sort_three(&a);
		else
			ft_sort_stack(&a, &b, arr);
	}
	return (free(arr.seq), ft_lstclear(&a.head), ft_lstclear(&b.head), 0);
}
