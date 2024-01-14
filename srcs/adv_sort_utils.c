/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:11:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 10:14:56 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_cost(t_list_ex *a, t_list_ex *b)
{
	t_list		*current_b;

	current_b = b->head;
	while (current_b)
	{
		if (current_b->flag && current_b->target_node->flag)
			current_b->cost
				= ft_max(current_b->index, current_b->target_node->index);
		else if (!current_b->flag && !current_b->target_node->flag)
			current_b->cost
				= ft_max(b->size - current_b->index,
					a->size - current_b->target_node->index);
		else if (current_b->flag && !current_b->target_node->flag)
			current_b->cost
				= current_b->index + (a->size - current_b->target_node->index);
		else if (!current_b->flag && current_b->target_node->flag)
			current_b->cost
				= (b->size - current_b->index) + current_b->target_node->index;
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
		biggest = 2147483648;
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
		ft_trgt_check(a, target_node, current_b, biggest);
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

void	ft_get_cheapest_to_top_b(t_list_ex *b, t_list *to_top)
{
	while (b->head != to_top)
	{
		if (to_top->index <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	ft_get_cheapest_to_top_a(t_list_ex *a, t_list *to_top)
{
	while (a->head != to_top)
	{
		if (to_top->index <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}
