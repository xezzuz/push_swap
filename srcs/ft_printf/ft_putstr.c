/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:32:37 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/05 12:34:26 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_putstr(char *str)
{
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		return_value = ft_putchar(str[i]);
		if (return_value == -1)
			return (-1);
		i++;
	}
	return (i);
}
