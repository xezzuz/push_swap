/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:49:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/01/16 11:52:14 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				flag;
	int				cost;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_list;

typedef struct s_list_ex
{
	t_list			*head;
	int				size;
	t_list			*cheapest;
}	t_list_ex;

typedef struct s_arrays
{
	int				*seq;
	int				seq_len;
}	t_arrays;

typedef struct s_pivot
{
	int				init;
	int				sec;
	int				prev;
}	t_pivot;

//	LIBFT
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
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
void		ft_sort_int_tab(int *tab, int size);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

//	GET_NEXT_LINE
char		*get_next_line(int fd);

//	PUSH_SWAP
int			*ft_parse_check(char **argv, t_arrays *arr);
void		ft_exit(int x);
void		ft_free_matrix(char ***matrix);
int			ft_check_num(char **matrix);
int			ft_matrix_size(char **matrix);
int			ft_is_blank(char **argv);
int			ft_check_duplicates(int *array, int n);
void		ft_stack_init(t_list_ex *a, int **seq, int n);
int			ft_is_sorted(t_list_ex *a);
void		ft_sort_three(t_list_ex *a);
void		sa(t_list_ex *a);
void		sb(t_list_ex *b);
void		ss(t_list_ex *a, t_list_ex *b);
void		rotate(t_list_ex *a);
void		ra(t_list_ex *a);
void		rb(t_list_ex *b);
void		rr(t_list_ex *a, t_list_ex *b);
void		reverse_rotate(t_list_ex *a);
void		rra(t_list_ex *a);
void		rrb(t_list_ex *b);
void		rrr(t_list_ex *a, t_list_ex *b);
void		push(t_list_ex *from, t_list_ex *to);
void		pa(t_list_ex *a, t_list_ex *b);
void		pb(t_list_ex *a, t_list_ex *b);

#endif