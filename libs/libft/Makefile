# Program name and output directory
NAME = libft.a
OUTPUT_DIR = .

# Other directories
INCL_DIR = incl
SRCS_ROOT_DIR = srcs
OBJS_ROOT_DIR = objs
MODULES	= libft_Libc libft_nonLibc libft_bonus ft_printf get_next_line
SRCS_DIR = $(addprefix $(SRCS_ROOT_DIR)/,$(MODULES))
OBJS_DIR = $(addprefix $(OBJS_ROOT_DIR)/,$(MODULES))

# Files
INCL = $(INCL_DIR)/libft.h
SRCS = $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

# Compiler and options
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
UI_FLAGS :=	-I$(INCL_DIR)

# ------------------------------------------------
# Phony targets
.PHONY: all clean fclean re update norm

# Link objects
all: $(NAME)
$(NAME): $(OBJS)
	@echo "----------------"
	@echo "make $(NAME) OBJS done.\n"
	ar rcs $@ $(OBJS)
	@echo "----------------"
	@echo "make $(NAME) done.\n"

# Compile objects
$(OBJS_ROOT_DIR)/%.o: $(SRCS_ROOT_DIR)/%.c | $(OBJS_DIR) $(INCL)
	$(CC) $(CFLAGS) $(UI_FLAGS) -c $< -o $@

# Make objs directory
$(OBJS_DIR): objs
	mkdir -p $(OBJS_DIR)
objs:
	mkdir -p objs

# rules for cleaning
clean:
	rm -f $(OBJS)
	rm -fd $(OBJS_DIR)
	rm -fd objs
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
re: fclean all

# non mandatory
update:	fclean
	make
norm:
	norminette $(SRCS) $(INCL)