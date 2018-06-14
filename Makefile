# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhuang <yhuang@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/09 01:14:30 by yhuang            #+#    #+#              #
#    Updated: 2018/06/11 18:34:50 by yhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main check_error parse draw_line create_map 

SRCDIR = src/

LIBS = -L libft -lft -L minilibx_macos -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra

CC = gcc

HEADERS = -I libft -I get_next_line -I minilibx_macos

all: $(NAME)
	
$(NAME): 
	$(CC) $(FLAGS) $(LIBS) $(FRAMEWORKS) $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC))) get_next_line/get_next_line.c -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all
