/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:16:13 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/08 14:24:58 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_get_max(t_list_ex *a)
{
	t_list		*current;
	t_list		*max;

	max = a->head;
	current = a->head->next;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

void	ft_sort_three(t_list_ex *a)
{
	t_list		*max_node;

	max_node = ft_get_max(a);
	if (max_node == a->head)
		ra(a);
	else if (max_node == a->head->next)
		rra(a);
	if (a->head->content > a->head->next->content)
		sa(a);
}
