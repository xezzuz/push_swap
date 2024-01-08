/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/08 14:01:16 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_parse_and_stock(char **argv, t_list_ex *a, t_arrays *arr)
{
	arr->seq = ft_parse_check(argv, arr);
	if (!arr->seq)
		return (0);
	if (!arr->seq_len)
		ft_exit(1);
	ft_print_int(arr->seq, arr->seq_len);
	printf("\n");
	arr->lis = ft_extract_lis(arr);
	if (!arr->lis)
		return (free(arr->seq), 0);
	ft_print_int(arr->lis, arr->lis_len);
	printf("\n");
	ft_stack_init(a, &arr->seq, arr->seq_len);
	ft_print_ll(&a->head);
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
		if (a.size == 3)
			ft_sort_three(&a);
	}

	// atexit(x);
	// free lis and stack a
	// ft_stack_init(&a, &b, lis, lis, length);
	return (0);
}
