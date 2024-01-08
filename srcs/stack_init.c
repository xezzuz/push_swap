/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:12:20 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/08 13:22:50 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_list_ex *a)
{
	t_list		*current;

	current = a->head;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_stack_init(t_list_ex *a, int **seq, int n)
{
	int		i;
	t_list	*node;

	i = 0;
	while (i < n)
	{
		node = ft_lstnew((*seq)[i]);
		ft_lstadd_back(&a->head, node);
		i++;
	}
	a->size = ft_lstsize(a->head);
	printf(" SIZE = [%d]\n", a->size);
	free(*seq);
}
