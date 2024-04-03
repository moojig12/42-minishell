# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 19:08:35 by nmandakh          #+#    #+#              #
#    Updated: 2024/04/03 20:06:30 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
UI_FLAGS :=	-I$(INCL_DIR) -I$(LIBFT_INCL_DIR)
UL_FLAGS := -L$(LIBFT_DIR)
LL_FLAGS := $(LIBFT_LL_FLAGS) -lreadline

# Link Targets
all:	$(NAME)

$(NAME): $(OBJS) | libft
	@echo "--------------------------------"
	@echo "make OBJECTS done.\n"
	$(CC) $(UI_FLAGS) $(UL_FLAGS) $^ $(LL_FLAGS) -o $@
	@echo "--------------------------------"
	@echo "make $(NAME) done.\n"
	chmod 777 $(NAME)
	@echo "--------------------------------"
	@echo "change permission of $(NAME) done.\n"

# Compile Targets
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(UI_FLAGS) -c $< -o $@
$(OBJS_DIR):
	mkdir $(OBJS_DIR)

# make libft
libft: $(LIBFT)
$(LIBFT):
	@echo "Compiling libft library..."
	make -C $(LIBFT_DIR)
	@echo "----------------"
	@echo "make libft done.\n"

clean:
		rm -rf $(OBJS)
		rm -df $(OBJS_DIR)
		make -C $(LIBFT_DIR) clean

fclean:		clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_DIR)

re:		fclean all

update:	fclean
		make

norm:
		norminette $(SRCS) $(INCL)

.PHONY = all clean fclean re update norm
