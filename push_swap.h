/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:49:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/08 14:39:21 by nazouz           ###   ########.fr       */
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
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_list_ex
{
	t_list			*head;
	int				size;
}	t_list_ex;

typedef struct s_arrays
{
	int				*seq;
	int				seq_len;
	int				*lis;
	int				lis_len;
}	t_arrays;

//	LIBFT
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		**ft_split(char const *s, char c);
long long	ft_atoll(const char *str);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);

//	PRINTF
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_printhex(unsigned int n, char *hex);
int			ft_printu(unsigned int n);
int			ft_print_add(void *ptr);
int			ft_printf(const char *format, ...);

//	PUSH_SWAP
int			*ft_parse_check(char **argv, t_arrays *arr);
void		ft_exit(int x);
void		ft_free_matrix(char ***matrix);
int			*ft_extract_lis(t_arrays *arr);
int			ft_check_num(char **matrix);
int			ft_matrix_size(char **matrix);
int			ft_is_blank(char **argv);
int			ft_check_duplicates(int *array, int n);
void		ft_stack_init(t_list_ex *a, int **seq, int n);
int			ft_is_sorted(t_list_ex *a);

void		ft_sort_three(t_list_ex *a);
void		sa(t_list_ex *a);
void		rotate(t_list_ex *a);
void		ra(t_list_ex *a);
void		rb(t_list_ex *b);
void		rr(t_list_ex *a, t_list_ex *b);
void		reverse_rotate(t_list_ex *a);
void		rra(t_list_ex *a);
void		rrb(t_list_ex *b);

//	HELPERS
void		ft_print_matrix(char **matrix);
void		ft_print_int(int *array, int length);
void		ft_print_ll(t_list **lst);
void		x();

#endif