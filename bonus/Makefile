# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:59:19 by samjaabo          #+#    #+#              #
#    Updated: 2023/03/05 16:27:31 by samjaabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB_NAME = library.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCSX = main.c get_next_line.c get_next_line_utils.c map_check_path_algo.c \
		moves.c map_rules.c so_long_utils.c elements.c on_exit.c libft.c

SRCS = $(SRCSX:.c=_bonus.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(LIB_NAME)

re: fclean all

$(NAME): $(OBJS)
	@$(CC) $(MLXFLAGS) -o $(NAME) $(OBJS)


%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	@./so_long map.ber