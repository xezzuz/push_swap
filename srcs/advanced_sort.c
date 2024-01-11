/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:12 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/11 19:22:29 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_cost(t_list_ex *a, t_list_ex *b)
{
	t_list		*current_b;

	current_b = b->head;
	while (current_b)
	{
		if (current_b->flag && current_b->target_node->flag) // if both above median
			current_b->cost = ft_max(current_b->index, current_b->target_node->index);
		else if (!current_b->flag && !current_b->target_node->flag) // if both below median
			current_b->cost = ft_max(b->size - current_b->index, a->size - current_b->target_node->index);
		else if (current_b->flag && !current_b->target_node->flag)
			current_b->cost = current_b->index + (a->size - current_b->target_node->index);
		else if (!current_b->flag && current_b->target_node->flag)
			current_b->cost = (b->size - current_b->index) + current_b->target_node->index;
		current_b = current_b->next;
	}
}

void	ft_get_target_nodes(t_list_ex *a, t_list_ex *b)
{
	t_list		*current_a;
	t_list		*current_b;
	t_list		*target_node;
	long		biggest;

	current_b = b->head;
	while (current_b)
	{
		biggest = LONG_MAX;
		current_a = a->head;
		while (current_a)
		{
			if (current_a->content > current_b->content
				&& current_a->content < biggest)
			{
				biggest = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (biggest == LONG_MAX)
			current_b->target_node = ft_get_min(a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
	}
}

void	ft_get_cheapest(t_list_ex *b)
{
	t_list		*current;

	current = b->head;
	if (!current)
		return ;
	if (current->next)
	{
		b->cheapest = current;
		current = current->next;
		while (current)
		{
			if (!b->cheapest->cost)
				return ;
			if (current->cost < b->cheapest->cost)
				b->cheapest = current;
			current = current->next;
		}
	}
	else
		b->cheapest = current;
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

void	ft_sort_stack(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	ft_stack_to_lis(a, b, arr);
	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
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
