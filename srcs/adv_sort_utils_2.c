/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/13 20:41:30 by nazouz           ###   ########.fr       */
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

void	ft_target_check(t_list_ex *a, t_list *target, t_list *current_b, long biggest)
{
	
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
