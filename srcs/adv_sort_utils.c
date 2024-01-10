/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:11:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/10 14:12:06 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int			size;
	int			i;

	current = a->head;
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (ft_is_in_lis(current->content, arr))
			ra(a);
		else
			pb(a, b);
		current = a->head;
		i++;
	}
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
