# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:59:19 by samjaabo          #+#    #+#              #
#    Updated: 2023/01/09 09:21:58 by samjaabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
CC = cc
CFLAGS = 

SRCS = main.c get_next_line.c get_next_line_utils.c map_check_path_algo.c window.c map_rules.c so_long_utils.c tmp_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o:%.c header.h
	@$(CC) $(CFLAGS) -c $< -o $@

run: all clean
	@clear
	@$(CC) $(CFLAGS) $(NAME)
	@./a.out


window: all clean
	@gcc -o window.a $(NAME) -lmlx -framework OpenGL -framework AppKit
	@./window.a