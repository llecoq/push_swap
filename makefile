# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 11:54:42 by llecoq            #+#    #+#              #
#    Updated: 2021/05/16 17:31:58 by llecoq           ###   ########lyon.fr    #
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
		ft_putchar.c ft_lstlast.c ft_putstr.c ft_store_list.c\
		ft_lstdelone.c ft_split.c ft_strlen.c\

OBJS_HEADER = $(addprefix ./include/, $(HEADER))

OBJS_SRCS = $(addprefix ./srcs/, $(SRCS:.c=.o))

OBJS_UTILS = $(addprefix ./utils/, $(UTILS:.c=.o))

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

$(NAME):		$(OBJS_SRCS) $(OBJS_UTILS)
					@printf "$(ERASE)$(GREEN)-> Files .o Created with success$(END)\n"
					@$(CC) $(FLAGS) $(OBJS_SRCS) $(OBJS_UTILS) -I $(OBJS_HEADER)
					@mv a.out $(NAME)
					@printf "$(CYAN)-> Executable file push_swap created with success!\n$(END)"

all:		$(NAME)


%.o: %.c $(OBJS_HEADER)
		 @$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./include
		 @printf "$(ERASE)$(YELLOW)$<.............$(END)"

norme:		
			norminette $(addprefix ./srcs/, $(SRCS))
			norminette $(addprefix ./utils/, $(UTILS))
			norminette $(addprefic ./includes/, $(HEADER)

clean:		
			@$(RM) $(OBJS_UTILS)
			@$(RM) $(NAME)
			@$(RM) $(OBJS_SRCS)
			@$(RM) $(OBJS_UTILS)

fclean:		clean
			@printf "$(ERASE)$(RED)All files cleaned$(END)\n"

re:			fclean all

.PHONY:		all fclean clean re