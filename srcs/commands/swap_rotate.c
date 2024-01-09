/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:34:41 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/09 17:17:50 by nazouz           ###   ########.fr       */
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
	ft_print_ll(&a->head);
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
	ft_printf("ra\n");
	ft_print_ll(&a->head);
}

void	rb(t_list_ex *b)
{
	rotate(b);
	ft_printf("rb\n");
	ft_print_ll(&b->head);
}

void	rr(t_list_ex *a, t_list_ex *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	ft_printf("A:\n");
	ft_print_ll(&a->head);
	ft_printf("B:\n");
	ft_print_ll(&b->head);
}
