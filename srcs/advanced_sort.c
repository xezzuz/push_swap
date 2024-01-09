/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:10:12 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/09 21:15:11 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	ft_is_in_lis(int x, t_arrays arr)
{
	int		i;

	i = 0;
	while (i < arr.lis_len)
	{
		if (x == arr.lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_stack_to_lis(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	t_list		*current;
	int			i;

	current = a->head;
	i = 0;
	while (i < a->size)
	{
		if (ft_is_in_lis(current->content, arr))
			ra(a);
		else
			pb(a, b);
		current = a->head;
		i++;
	}
}

void	ft_sort_stack(t_list_ex *a, t_list_ex *b, t_arrays arr)
{
	ft_stack_to_lis(a, b, arr);
	ft_get_target_nodes(a, b);

	t_list	*current_b;

	current_b = b->head;
	while (current_b)
	{
		printf("target node of [%d] is [%d]\n", current_b->content, current_b->target_node->content);
		current_b = current_b->next;
	}
}
