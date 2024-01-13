# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:46:23 by nazouz            #+#    #+#              #
#    Updated: 2024/01/13 16:08:02 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g3

INCLUDES		=	./push_swap.h

RM				=	rm -f

SRCS				=	\
					./srcs/libft/ft_split.c \
					./srcs/libft/ft_strlen.c \
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
					./srcs/parse.c \
					./srcs/parse_utils.c \
					./srcs/exit.c \
					./srcs/stack_utils.c \
					./srcs/advanced_sort.c \
					./srcs/adv_sort_utils.c \
					./srcs/adv_sort_utils_2.c \
					./srcs/commands/rotate.c \
					./srcs/commands/rev_rotate.c \
					./srcs/commands/push.c \
					./srcs/commands/swap.c \
					./srcs/main.c

OBJS			=	$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

cc : all clean	#############################

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all