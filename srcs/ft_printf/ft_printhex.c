/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:59:24 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/05 12:34:14 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_printhex(unsigned int n, char *hex)
{
	int					count;
	int					return_value;

	count = 0;
	return_value = 0;
	if (n >= 16)
	{
		return_value = ft_printhex((n / 16), hex);
		if (return_value == -1)
			return (-1);
		count += return_value;
	}
	return_value = ft_putchar(hex[n % 16]);
	if (return_value == -1)
		return (-1);
	return (count + return_value);
}
