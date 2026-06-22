# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 16:13:21 by quewonchin        #+#    #+#              #
#    Updated: 2026/05/19 19:52:46 by qixu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
LIBFT	= lib/libft
CFLAGS	= -Wall -Werror -Wextra -I.
READLINE_FLAGS	= -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include -lreadline
CFILES	= minishell.c
OFILES	= $(CFILES:.c=.o)

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(READLINE_FLAGS) -o $(NAME) $(OFILES) -L$(LIBFT) -lft

clean:
	rm -f $(OFILES)
	make clean -C $(LIBFT)

fclean: clean
	rm -f ./$(NAME)
	make fclean -C $(LIBFT)

re: fclean all
