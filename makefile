# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 11:54:42 by llecoq            #+#    #+#              #
#    Updated: 2021/05/15 11:57:44 by llecoq           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE       =   \033[2K\r
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

NAME = push_swap

HEADER = push_swap.h

SRCS = main.c handle_error.c

UTILS = ft_atoi.c ft_isdigit.c ft_lstadd_back.c ft_lstnew.c ft_lstclear.c\
		ft_putchar.c ft_lstlast.c ft_putstr.c

OBJS_SRCS = $(addprefix ./scrs/, $(SRCS:.c=.o))

OBJS_UTILS = $(addprefix ./utils/, $(UTILS:.c=.o))

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME =		

clean:		@RM $(OBJS_UTILS)

fclean:		clean
			@printf "$(ERASE)$(RED)All files .o cleaned$(END)\n"

re:			fclean all

.PHONY:		all fclean clean re
