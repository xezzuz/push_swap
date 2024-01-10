/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:34:41 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/10 13:29:04 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_list_ex *a)
{
	int		temp;

	temp = a->head->content;
	a->head->content = a->head->next->content;
	a->head->next->content = temp;
	ft_printf("sa\n");
}

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
	ft_printf("ra\n");
}

void	rb(t_list_ex *b)
{
	rotate(b);
	b->size = ft_lstsize(b->head);
	ft_printf("rb\n");
}

void	rr(t_list_ex *a, t_list_ex *b)
{
	rotate(a);
	a->size = ft_lstsize(a->head);
	rotate(b);
	b->size = ft_lstsize(b->head);
	ft_printf("rr\n");
}
