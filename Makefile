NAME = ft_ping

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src/
OBJ_DIR = obj/

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
HDR := $(shell find $(SRC_DIR) -type f -name "*.h")

OBJ := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft/

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR) $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
