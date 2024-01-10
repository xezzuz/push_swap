/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:49:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/10 17:53:49 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	else// if (min->index > a->size / 2)
	{
		cost = a->size - min->index;
		while (cost--)
			rra(a);
	}
	printf("final cost for [%d] is [%d]", min->content, cost);
}
