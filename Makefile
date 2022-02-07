NAME = ft_ping

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
HDR := $(shell find $(SRC_DIR) -type f -name "*.h")

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
