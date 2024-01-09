/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:32 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/09 17:18:00 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_list_ex *a)
{
	t_list		*last;
	t_list		*current;

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
	ft_printf("rra\n");
	ft_print_ll(&a->head);
}

void	rrb(t_list_ex *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	ft_print_ll(&b->head);
}

void	rrr(t_list_ex *a, t_list_ex *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	ft_printf("A:\n");
	ft_print_ll(&a->head);
	ft_printf("B:\n");
	ft_print_ll(&b->head);
}
