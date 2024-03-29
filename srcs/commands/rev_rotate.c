/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:32 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/16 18:23:48 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_list_ex *a)
{
	t_list		*last;
	t_list		*current;

	if (!a->head || !a->head->next)
		return ;
	current = a->head;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = a->head;
	a->head = last;
}

void	rra(t_list_ex *a)
{
	reverse_rotate(a);
	a->size = ft_lstsize(a->head);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list_ex *b)
{
	reverse_rotate(b);
	b->size = ft_lstsize(b->head);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list_ex *a, t_list_ex *b)
{
	reverse_rotate(a);
	a->size = ft_lstsize(a->head);
	reverse_rotate(b);
	b->size = ft_lstsize(b->head);
	ft_putstr_fd("rrr\n", 1);
}
