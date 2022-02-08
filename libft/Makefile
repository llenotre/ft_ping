# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llenotre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 20:17:20 by llenotre          #+#    #+#              #
#    Updated: 2018/11/16 10:18:43 by llenotre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_factorial.c\
		ft_fibonacci.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isspace.c\
		ft_itoa.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_match.c\
		ft_max.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_min.c\
		ft_pow.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_sort.c\
		ft_sqrt.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_swap.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_treedel.c\
		ft_treedelone.c\
		ft_treenew.c\
		ft_treesearch.c

.PHONY: all $(NAME) clean fclean re
.SILENT: all $(NAME) $(NAME).a clean fclean re

all: $(NAME)

$(NAME): $(NAME).a

$(NAME).a:
	$(COMPILER) $(FLAGS) -c $(SRCS)
	ar rc $(NAME).a *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME).a

re: fclean all
