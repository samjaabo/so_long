# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:59:19 by samjaabo          #+#    #+#              #
#    Updated: 2023/02/20 16:28:46 by samjaabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB_NAME = library.a
CC = cc
CFLAGS = -Wall -Wextra

SRCS = main.c get_next_line.c get_next_line_utils.c map_check_path_algo.c \
		window.c map_rules.c so_long_utils.c tmp_utils.c \
		elements.c on_exit.c libft.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(LIB_NAME)

re: fclean all

$(NAME): $(OBJS)
	@ar rc $(LIB_NAME) $(OBJS)

%.o: %.c header.h
	@$(CC) $(CFLAGS) -c $< -o $@

run: all clean
	@clear
	@$(CC) $(CFLAGS) $(NAME)
	@./a.out


window: all clean
	@gcc $(LIB_NAME) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@./so_long tests.txt