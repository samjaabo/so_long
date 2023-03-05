# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:59:19 by samjaabo          #+#    #+#              #
#    Updated: 2023/03/05 17:34:42 by samjaabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c get_next_line.c get_next_line_utils.c map_check_path_algo.c \
		moves.c map_rules.c so_long_utils.c elements.c on_exit.c libft.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ./bonus/main_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
			./bonus/map_check_path_algo_bonus.c ./bonus/moves_bonus.c ./bonus/map_rules_bonus.c \
			./bonus/so_long_utils_bonus.c ./bonus/elements_bonus.c ./bonus/on_exit_bonus.c ./bonus/libft_bonus.c \
			./bonus/enemy_bonus.c ./bonus/utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all


ifeq ($(MAKECMDGOALS),bonus)
$(NAME): $(BONUS_OBJS)
	$(CC) $(MLXFLAGS) -o $(NAME) $(BONUS_OBJS)
else
$(NAME): $(OBJS)
	$(CC) $(MLXFLAGS) -o $(NAME) $(OBJS)
endif

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@
