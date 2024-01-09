/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:28:04 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/09 17:38:21 by nazouz           ###   ########.fr       */
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
	ft_printf("pa\n");
	printf("A:\n");
	ft_print_ll(&a->head);
	printf("\nB:\n");
	ft_print_ll(&b->head);
}

void	pb(t_list_ex *a, t_list_ex *b)
{
	push(a, b);
	ft_printf("pb\n");
	printf("A:\n");
	ft_print_ll(&a->head);
	printf("\nB:\n");
	ft_print_ll(&b->head);
}
