/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/12 20:23:00 by nazouz           ###   ########.fr       */
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

int	ft_is_in_part(int x, t_arrays arr, int i, int j)
{
	while (i < j)
	{
		if (arr.seq[i] == x)
			return (1);
		i++;
	}
	return (0);
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
