/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/14 10:27:45 by nazouz           ###   ########.fr       */
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

void	ft_pivots_init(t_list_ex *a, t_pivot *p)
{
	p->prev = -1;
	p->sec = a->size / 4;
	p->init = a->size / 2;
}

void	ft_trgt_check(t_list_ex *a, t_list *trgt, t_list *cur_b, long big)
{
	if (big == 2147483648)
		cur_b->target_node = ft_get_min(a);
	else
		cur_b->target_node = trgt;
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
