/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:34:41 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/13 15:56:29 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	rotate(a);
	a->size = ft_lstsize(a->head);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list_ex *b)
{
	rotate(b);
	b->size = ft_lstsize(b->head);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list_ex *a, t_list_ex *b)
{
	rotate(a);
	a->size = ft_lstsize(a->head);
	rotate(b);
	b->size = ft_lstsize(b->head);
	ft_putstr_fd("rr\n", 1);
}
