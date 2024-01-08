/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/08 11:06:10 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_parse_and_stock(char **argv, t_list_ex *a)
{
	int		length;
	int		*lis;
	int		*seq;

	seq = ft_parse_check(argv, &length);
	if (!seq)
		return (0);
	if (length == 0)
		ft_exit(1);
	ft_print_int(seq, length);
	printf("\n");
	lis = ft_extract_lis(seq, length);
	if (!lis)
		return (free(seq), 0);
	ft_print_int(lis, length);
	printf("\n");
	ft_stack_init(a, &seq, length);
	free(lis);
	// t_list *current;
	// current = *a;
	// while (current)
	// {
	// 	printf("[%d]\n", current->content);
	// 	current = current->next;
	// }
	return (1);
}

int main(int argc, char **argv)
{
	t_list_ex	a;
	t_list_ex	b;

	a.head = NULL;
	b.head = NULL;
	if (argc == 1)
		return (0);
	if (!ft_parse_and_stock(argv, &a))
		ft_exit(0);
	atexit(x);
	// ft_stack_init(&a, &b, lis, lis, length);
	return (0);
}
