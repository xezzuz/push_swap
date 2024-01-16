# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:46:23 by nazouz            #+#    #+#              #
#    Updated: 2024/01/15 17:28:50 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDES		=	./includes/push_swap.h

INCLUDES_BONUS	=	./includes/push_swap_bonus.h

RM				=	rm -f

SRCS				=	\
					./srcs/libft/ft_strlen.c \
					./srcs/libft/ft_split.c \
					./srcs/libft/ft_strjoin.c \
					./srcs/libft/ft_strdup.c \
					./srcs/libft/ft_strlcpy.c \
					./srcs/libft/ft_memcpy.c \
					./srcs/libft/ft_atoll.c \
					./srcs/libft/ft_lstadd_back.c \
					./srcs/libft/ft_lstclear.c \
					./srcs/libft/ft_lstlast.c \
					./srcs/libft/ft_lstnew.c \
					./srcs/libft/ft_lstsize.c \
					./srcs/libft/ft_sort_int_tab.c \
					./srcs/libft/ft_putstr_fd.c \
					./srcs/libft/ft_putchar_fd.c \
					./srcs/mandatory/parse.c \
					./srcs/mandatory/parse_utils.c \
					./srcs/mandatory/stack_utils.c \
					./srcs/mandatory/advanced_sort.c \
					./srcs/mandatory/adv_sort_utils.c \
					./srcs/mandatory/adv_sort_utils_2.c \
					./srcs/commands/rotate.c \
					./srcs/commands/rev_rotate.c \
					./srcs/commands/push.c \
					./srcs/commands/swap.c \
					./srcs/mandatory/main.c

SRCS_BONUS			=	\
					./srcs/libft/ft_strlen.c \
					./srcs/libft/ft_split.c \
					./srcs/libft/ft_strncmp.c \
					./srcs/libft/ft_strjoin.c \
					./srcs/libft/ft_strdup.c \
					./srcs/libft/ft_strlcpy.c \
					./srcs/libft/ft_memcpy.c \
					./srcs/libft/ft_atoll.c \
					./srcs/libft/ft_lstadd_back.c \
					./srcs/libft/ft_lstclear.c \
					./srcs/libft/ft_lstlast.c \
					./srcs/libft/ft_lstnew.c \
					./srcs/libft/ft_lstsize_bonus.c \
					./srcs/libft/ft_sort_int_tab.c \
					./srcs/libft/ft_putstr_fd.c \
					./srcs/libft/ft_putchar_fd.c \
					./srcs/get_next_line/get_next_line.c \
					./srcs/bonus/parse_bonus.c \
					./srcs/bonus/parse_utils_bonus.c \
					./srcs/commands_bonus/rotate.c \
					./srcs/commands_bonus/rev_rotate.c \
					./srcs/commands_bonus/push.c \
					./srcs/commands_bonus/swap.c \
					./srcs/bonus/main_bonus.c

OBJS			=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $@

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all