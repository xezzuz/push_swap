/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:12:20 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 19:27:37 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_get_min(t_list_ex *a)
{
	t_list		*current;
	t_list		*min;

	current = a->head->next;
	min = a->head;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

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

int	ft_is_sorted(t_list_ex *a)
{
	t_list		*current;

	current = a->head;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_stack_init(t_list_ex *a, int **seq, int n)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < n)
	{
		node = ft_lstnew((*seq)[i]);
		if (!node)
		{
			ft_lstclear(&a->head);
			free (*seq);
			return ;
		}
		ft_lstadd_back(&a->head, node);
		i++;
	}
	a->size = ft_lstsize(a->head);
}
