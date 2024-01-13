/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:56:15 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/13 15:57:39 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_list_ex *a)
{
	int		temp;

	temp = a->head->content;
	a->head->content = a->head->next->content;
	a->head->next->content = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list_ex *b)
{
	int		temp;

	temp = b->head->content;
	b->head->content = b->head->next->content;
	b->head->next->content = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list_ex *a, t_list_ex *b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}
