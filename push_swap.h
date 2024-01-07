/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:49:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/07 13:22:41 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>

//	LIBFT
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(char const *s, char c);
long long	ft_atoll(const char *str);

//	PRINTF
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_printhex(unsigned int n, char *hex);
int		ft_printu(unsigned int n);
int		ft_print_add(void *ptr);
int		ft_printf(const char *format, ...);

//	PUSH_SWAP
int		*ft_parse_check(char **argv, int *length);
void	ft_exit(int x);
int		*ft_extract_lis(int *seq, int n);
int		ft_check_num(char **matrix);
int		ft_matrix_size(char **matrix);
int		ft_is_blank(char **argv);
int		ft_check_duplicates(int *array, int n);

//	HELPERS
void	ft_print_matrix(char **matrix);
void	ft_print_int(int *array, int length);

#endif