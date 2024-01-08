# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 11:46:23 by nazouz            #+#    #+#              #
#    Updated: 2024/01/08 14:39:51 by nazouz           ###   ########.fr        #
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
					./srcs/ft_printf/ft_printf.c \
					./srcs/ft_printf/ft_print_add.c \
					./srcs/ft_printf/ft_printhex.c \
					./srcs/ft_printf/ft_printu.c \
					./srcs/ft_printf/ft_putchar.c \
					./srcs/ft_printf/ft_putnbr.c \
					./srcs/ft_printf/ft_putstr.c \
					./srcs/parse.c \
					./srcs/parse_utils.c \
					./srcs/exit.c \
					./srcs/helpers.c \
					./srcs/lis.c \
					./srcs/stack_init.c \
					./srcs/push_swap.c \
					./srcs/swap_rotate.c \
					./srcs/rev_rotate.c \
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