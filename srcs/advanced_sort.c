/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:12 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/12 21:26:44 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

// void	ft_move_to_b(t_list_ex *a, t_list_ex *b, t_arrays arr)
// {
// 	while (b->size < arr.seq_len / 3)
// 	{
// 		if (ft_is_in_part(a->head->content, arr, 0, arr.seq_len / 3))
// 			pb(a, b);
// 		else
// 			ra(a);
// 	}
// 	while (b->size < (arr.seq_len / 3) * 2)
// 	{
// 		if (ft_is_in_part(a->head->content, arr, arr.seq_len / 3, (arr.seq_len / 3) * 2))
// 			pb(a, b);
// 		else
// 			ra(a);
// 	}
// 	while (a->size > 3)
// 	{
// 		if (ft_is_in_part(a->head->content, arr, (arr.seq_len / 3) * 2, arr.seq_len))
// 			pb(a, b);
// 		else
// 			ra(a);
// 	}
// }

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

void    push_to_b(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
    int    pivot;
	int		sec;
	int		prev;

	prev = -1;
    sec = a->size / 6;
    pivot = a->size / 2;
    while (a->size > 3)
    {
		 if (b->size > 1 && ft_get_index(b->head->content, arr.seq, arr.seq_len) < sec
            && ft_get_index(b->head->content, arr.seq, arr.seq_len) > prev && ft_get_index(a->head->content, arr.seq, arr.seq_len) >= pivot)
            rr(a, b);
        else if (b->size > 1 && ft_get_index(b->head->content, arr.seq, arr.seq_len) < sec
            && ft_get_index(b->head->content, arr.seq, arr.seq_len) > prev)
            rb(b);
        if (ft_get_index(a->head->content, arr.seq, arr.seq_len) < pivot)
            pb(a, b);
		else
			ra(a);
        if (b->size >= pivot)
		{
        	prev = pivot;
            sec = ft_lstsize(a->head) / 6 + pivot;
		    pivot = ft_lstsize(a->head) / 2 + pivot;
		}
		b->size = ft_lstsize(b->head);
    }
}


void	ft_sort_stack(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	ft_sort_int_tab(arr.seq, arr.seq_len);
	// printf("seq_len = %d\n", arr.seq_len);
	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	// ft_move_to_b(a, b, arr);
	push_to_b(a, b, arr);
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
	// printf("\n\n=====> FINAL RESULT\n\nA:\n");
	// ft_print_ll(&a->head);
	// printf("\nB:\n");
	// ft_print_ll(&b->head);
	/*   ./push_swap 142 88 76 66 62 2 8 -4 55 77 44 99 -1   */
}
