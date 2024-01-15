/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:12 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 16:48:23 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_get_index(int content, int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == content)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_to_a(t_list_ex *a, t_list_ex *b)
{
	while (b->cheapest->index && b->cheapest->target_node->index)
	{
		if ((b->cheapest->index <= b->size / 2)
			&& (b->cheapest->target_node->index <= a->size / 2))
			rr(a, b);
		else if ((b->cheapest->index >= b->size / 2)
			&& (b->cheapest->target_node->index >= a->size / 2))
			rrr(a, b);
		else
			break ;
	}
	ft_get_cheapest_to_top_b(b, b->cheapest);
	ft_get_cheapest_to_top_a(a, b->cheapest->target_node);
	pa(a, b);
}

void	ft_move_to_b(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	t_pivot			p;

	ft_pivots_init(a, &p);
	while (a->size > 3)
	{
		if (b->size > 1
			&& ft_get_index(b->head->content, arr.seq, arr.seq_len) < p.sec
			&& ft_get_index(b->head->content, arr.seq, arr.seq_len) > p.prev
			&& ft_get_index(a->head->content, arr.seq, arr.seq_len) >= p.init)
			rr(a, b);
		else if (b->size > 1
			&& ft_get_index(b->head->content, arr.seq, arr.seq_len) < p.sec
			&& ft_get_index(b->head->content, arr.seq, arr.seq_len) > p.prev)
			rb(b);
		if (ft_get_index(a->head->content, arr.seq, arr.seq_len) < p.init)
			pb(a, b);
		else
			ra(a);
		if (b->size >= p.init)
		{
			p.prev = p.init;
			p.sec = ft_lstsize(a->head) / 4 + p.init;
			p.init = ft_lstsize(a->head) / 2 + p.init;
		}
	}
}

void	ft_sort_stack(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	ft_sort_int_tab(arr.seq, arr.seq_len);
	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	ft_move_to_b(a, b, arr);
	ft_sort_three(a);
	while (b->head)
	{
		ft_get_target_nodes(a, b);
		ft_get_cost(a, b);
		ft_get_cheapest(b);
		ft_move_to_a(a, b);
		a->size = ft_lstsize(a->head);
		b->size = ft_lstsize(b->head);
	}
	if (!ft_is_sorted(a))
		ft_final_check(a);
	free(arr.seq);
	ft_lstclear(&a->head);
}
