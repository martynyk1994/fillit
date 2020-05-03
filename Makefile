

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRC = src/data_convert.c src/input.c src/validation.c src/helper_functions.c src/solver.c

OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
LIB_PATH = libft/
INCLUDES_PATH = includes

all: $(NAME)

$(NAME): $(SRC)
	@make -C $(LIB_PATH)
	@$(CC) $(CC_FLAGS) -o $(NAME) -I$(INCLUDES_PATH) -I. $(SRC) $(LIB)

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
