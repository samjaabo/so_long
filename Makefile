# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samjaabo <samjaabo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 08:59:19 by samjaabo          #+#    #+#              #
#    Updated: 2023/01/06 19:02:52 by samjaabo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MyLibrary.a
CC = cc
CFLAGS = 

MAIN_SRC = main.c ft_utils.c window.c
MAIN_OBJS = $(MAIN_SRC:.c=.o)
# directory variables
LIBFT_DIR = ./libft/
GET_NEXT_LINE_DIR = ./get_next_line/
FT_PRINTF_DIR = ./ft_printf/

#src files
LIBFT_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c \
		ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_bzero.c ft_strrchr.c ft_strnstr.c \
		ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_atoi.c \
		ft_itoa.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strtrim.c ft_split.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

GET_NEXT_LINE_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c

FT_PRINTF_FILES = ft_printf_utils.c ft_printf.c ft_to_hex.c ft_to_nbr.c ft_to_put.c

#src files with path
LIBFT_SRCS = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))
GET_NEXT_LINE_SRCS = $(addprefix $(GET_NEXT_LINE_DIR),$(GET_NEXT_LINE_FILES))
FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_DIR),$(FT_PRINTF_FILES))
# object files variables
LIBFT_OBJS =	$(LIBFT_SRCS:%.c=%.o)
GET_NEXT_LINE_OBJS =	$(GET_NEXT_LINE_SRCS:%.c=%.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:%.c=%.o)

all: $(NAME)

clean:
	@rm -rf $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(FT_PRINTF_OBJS) $(MAIN_OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

$(NAME): $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(FT_PRINTF_OBJS) $(MAIN_OBJS)
	@ar rc $(NAME) $(LIBFT_OBJS) $(GET_NEXT_LINE_OBJS) $(FT_PRINTF_OBJS) $(MAIN_OBJS)

%.o: %.c header.h ./libft/libft.h ./get_next_line/get_next_line_bonus.h ./ft_printf/ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

run: all
	@clear
	@$(CC) $(CFLAGS) $(NAME)
	#@$ (MAKE) fclean
	@./a.out | cat -e


window: all
	@gcc -o window.a $(NAME) -lmlx -framework OpenGL -framework AppKit
	@./window.a