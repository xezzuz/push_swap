/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:33:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/07 12:10:02 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	int		length;

	i = 0;
	if (argc == 1)
		return (0);
	printf("ARGC = %d\n", argc);
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	if (!ft_parse_check(argv, &length))
		ft_exit(0); // free matrix
	// ft_print_matrix(ft_extract_args(argv));
	return (0);
}