/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:34:41 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/15 11:24:02 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	rotate(t_list_ex *a)
{
	t_list		*last;

	last = ft_lstlast(a->head);
	last->next = a->head;
	a->head = a->head->next;
	last->next->next = NULL;
}

void	ra(t_list_ex *a)
{
	if (!a->head)
		return ;
	rotate(a);
	a->size = ft_lstsize(a->head);
}

void	rb(t_list_ex *b)
{
	if (!b->head)
		return ;
	rotate(b);
	b->size = ft_lstsize(b->head);
}

void	rr(t_list_ex *a, t_list_ex *b)
{
	if (!a->head || !b->head)
		return ;
	rotate(a);
	a->size = ft_lstsize(a->head);
	rotate(b);
	b->size = ft_lstsize(b->head);
}
