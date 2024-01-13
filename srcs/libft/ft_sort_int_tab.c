/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:13:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/13 16:06:51 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	pass_num;
	int	i;
	int	temp_swap;

	i = 0;
	pass_num = 1;
	while (pass_num < size)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp_swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp_swap;
			}
			i++;
		}
		pass_num++;
		i = 0;
	}
}
