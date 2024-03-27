# Program name and output directory
NAME = libft.a
OUTPUT_DIR = .

# Other directories
INCLUDES_DIR = incl
SOURCES_DIR = scrs/*

# Files
HEADERS =	$(INCLUDES_DIR)/libft.h
SOURCES = 	$(wildcard $(SOURCES_DIR)/*.c)
OBJECTS =	$(SOURCES:.c=.o)

# Compiler and options
CC = cc
CFLAGS += -Wall -Wextra -Werror
DEST = $(OUTPUT_DIR)

# Phony targets
.PHONY: all clean fclean re aclean

# Targets
all: $(NAME)
$(NAME): $(OBJECTS)
	@echo "----------------"
	@echo "make $(NAME) OBJECTS done.\n"
	ar rcs $@ $(OBJECTS)
	@echo "----------------"
	@echo "make $(NAME) done.\n"
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
re: fclean all

# non mandatory
aclean: all clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)