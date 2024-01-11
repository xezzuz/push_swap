/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/11 14:10:51 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_get_flag(t_list *a, int size)
{
	while (a)
	{
		if (a->index <= size / 2)
			a->flag = 1;
		else
			a->flag = 0;
		a = a->next;
	}
}

void	ft_final_check(t_list_ex *a)
{
	t_list		*min;
	int			cost;

	min = ft_get_min(a);
	if (min->index <= a->size / 2)
	{
		cost = min->index;
		while (cost--)
			ra(a);
	}
	else
	{
		cost = a->size - min->index;
		while (cost--)
			rra(a);
	}
}

// void	ft_get_cost(t_list_ex *a, t_list_ex *b)
// {
// 	t_list		*current_b;
// 	int flag = 0;
// 	int target_moves;
// 	current_b = b->head;
// 	while (current_b)
// 	{
// 		if (current_b->index <= b->size / 2)
// 			current_b->cost = current_b->index;
// 		else if (current_b->index > b->size / 2)
// 		{	flag = 1;
// 			current_b->cost = b->size - current_b->index;}
			
// 		if (current_b->target_node->index <= a->size / 2)
// 		{
// 			target_moves = current_b->target_node->index;
// 			if (!flag)
// 			{
// 				if (current_b->target_node->index > current_b->cost)
// 					current_b->cost = current_b->target_node->index;
// 			}
// 			else
// 				current_b->cost += target_moves;
// 		}
// 		else if (current_b->target_node->index > a->size / 2)
// 		{
// 			target_moves = a->size - current_b->target_node->index;
// 			if (flag)
// 			{
// 				if (target_moves > current_b->cost)
// 					current_b->cost = target_moves;
// 			}
// 			else
// 				current_b->cost += target_moves;
// 		}
			
// 		// else if (current_b->target_node->index <= a->size / 2 && flag)
// 		// 	current_b->cost += current_b->target_node->index;
			
// 		// else if (current_b->target_node->index > a->size / 2)
// 		// 	current_b->cost += a->size - current_b->target_node->index;
// 		current_b = current_b->next;
// 	}
// }
