/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:56:15 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/16 18:15:32 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	sa(t_list_ex *a)
{
	int		temp;

	if (!a->head ||!a->head->next)
		return ;
	temp = a->head->content;
	a->head->content = a->head->next->content;
	a->head->next->content = temp;
}

void	sb(t_list_ex *b)
{
	int		temp;

	if (!b->head || !b->head->next)
		return ;
	temp = b->head->content;
	b->head->content = b->head->next->content;
	b->head->next->content = temp;
}

void	ss(t_list_ex *a, t_list_ex *b)
{
	sa(a);
	sb(b);
}
