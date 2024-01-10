/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:04 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/10 13:27:41 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list_ex *from, t_list_ex *to)
{
	t_list		*temp;

	temp = from->head;
	from->head = from->head->next;
	temp->next = to->head;
	to->head = temp;
}

void	pa(t_list_ex *a, t_list_ex *b)
{
	push(b, a);
	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	ft_printf("pa\n");
}

void	pb(t_list_ex *a, t_list_ex *b)
{
	push(a, b);
	a->size = ft_lstsize(a->head);
	b->size = ft_lstsize(b->head);
	ft_printf("pb\n");
}