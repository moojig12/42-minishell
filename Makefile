# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).
#
# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)

# name
OUTPUT_DIR = 		.
NAME = 				$(OUTPUT_DIR)/minishell

# dirs
INCL_DIR =			incl
SRCS_DIR =			srcs
OBJS_DIR =			objs
LIBFT_DIR =			libs/libft

# Files
INCL	=	$(wildcard $(INCL_DIR)/*.h) # FIX: change this before submit
# INCL	=	$(INCL_DIR)/minishell.h
SRCS	=	$(wildcard $(SRCS_DIR)/*.c) # FIX: change this before submit
# SRCS	=	$(SRCS_DIR)/main.c \
# 			$(SRCS_DIR)/tokenization.c \
# 			...
OBJS 	=	$(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

#libft
LIBFT_DIR =			libs/libft
LIBFT_INCL_DIR =	$(LIBFT_DIR)/incl
LIBFT =				$(LIBFT_DIR)/libft.a
LIBFT_LL_FLAGS +=	-lft

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g
UI_FLAGS :=	-I$(INCL_DIR) -I$(LIBFT_INCL_DIR)
UL_FLAGS := -L$(LIBFT_DIR)
LL_FLAGS := $(LIBFT_LL_FLAGS) -lreadline

# use gnu readline library in mac
ifeq ($(shell uname -s),Darwin)
    ifeq ($(shell uname -m),arm64)
        # Additional flags for M1 Mac
        RLDIR := /opt/homebrew/opt/readline
        UI_FLAGS += -I$(RLDIR)/include
        UL_FLAGS += -L$(RLDIR)/lib
    endif
endif

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