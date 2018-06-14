# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 19:01:28 by yhuang            #+#    #+#              #
#    Updated: 2018/03/01 12:24:54 by yhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

all: $(NAME)

$(NAME):
	@echo "\033[92mCompiling libft\033[0m"
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@echo "\033[31mDeleting objects\033[0m"
	@rm -f *.o

fclean: clean
	@echo "\033[31mDeleting $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
