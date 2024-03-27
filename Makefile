# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 19:08:35 by nmandakh          #+#    #+#              #
#    Updated: 2024/03/27 17:01:54 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g -lreadline
SRCS	=	srcs/main.c srcs/utils.c srcs/tokenization.c

NAME	=	minishell

all:	$(NAME)

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

update:		fclean
			make

norm:
			norminette $(srcs)

.PHONY = all clean fclean re update