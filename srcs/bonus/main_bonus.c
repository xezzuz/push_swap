/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:00:09 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/15 17:04:49 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	ft_exit(int x)
{
	if (x == 0)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_check_command(t_list_ex *a, t_list_ex *b, char *command)
{
	if (!ft_strncmp(command, "sa\n", ft_strlen(command)))
		sa(a);
	else if (!ft_strncmp(command, "sb\n", ft_strlen(command)))
		sb(b);
	else if (!ft_strncmp(command, "ss\n", ft_strlen(command)))
		ss(a, b);
	else if (!ft_strncmp(command, "pa\n", ft_strlen(command)))
		pa(a, b);
	else if (!ft_strncmp(command, "pb\n", ft_strlen(command)))
		pb(a, b);
	else if (!ft_strncmp(command, "ra\n", ft_strlen(command)))
		ra(a);
	else if (!ft_strncmp(command, "rb\n", ft_strlen(command)))
		rb(b);
	else if (!ft_strncmp(command, "rr\n", ft_strlen(command)))
		rr(a, b);
	else if (!ft_strncmp(command, "rra\n", ft_strlen(command)))
		rra(a);
	else if (!ft_strncmp(command, "rrb\n", ft_strlen(command)))
		rrb(b);
	else if (!ft_strncmp(command, "rrr\n", ft_strlen(command)))
		rrr(a, b);
	else
		return (free(command), 0);
	return (free(command), 1);
}

int	ft_get_commands(t_list_ex *a, t_list_ex *b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (!ft_check_command(a, b, command))
			return (0);
	}
	return (1);
}

int	ft_parse_and_stock(char **argv, t_list_ex *a, t_arrays *arr)
{
	arr->seq = ft_parse_check(argv, arr);
	if (!arr->seq)
		return (0);
	if (!arr->seq_len)
	{
		free (arr->seq);
		ft_exit(1);
	}
	ft_stack_init(a, &arr->seq, arr->seq_len);
	return (free(arr->seq), 1);
}

int	main(int argc, char **argv)
{
	t_list_ex	a;
	t_list_ex	b;
	t_arrays	arr;

	a.head = NULL;
	b.head = NULL;
	if (argc == 1)
		return (0);
	if (!ft_parse_and_stock(argv, &a, &arr))
		ft_exit(0);
	if (!ft_get_commands(&a, &b))
		return (ft_lstclear(&a.head), ft_lstclear(&b.head), ft_exit(0), 0);
	if (ft_is_sorted(&a) && !b.head)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (ft_lstclear(&a.head), ft_lstclear(&b.head), 0);
}
