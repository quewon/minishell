# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qixu <qixu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 16:13:21 by quewonchin        #+#    #+#              #
#    Updated: 2026/05/19 19:11:07 by qixu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -I.
CFILES	= minishell.c
OFILES	= $(CFILES:.c=.o)

.PHONY:	all clean fclean re

$(NAME): $(OFILES)
	$(CC) -o $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f ./$(NAME)

re: fclean all
