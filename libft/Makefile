# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkremnov <tkremnov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:01:54 by tkremnov          #+#    #+#              #
#    Updated: 2024/12/17 12:20:01 by tkremnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = ../include

SRC =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

GET_NEXT_LINE_SRC = get_next_line.c \
					get_next_line_utils.c

FT_PRINTF_SRC = ft_printf.c \
				ft_printf_helper_fun1.c \
				ft_printf_helper_fun2.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE_SRC:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE_DIR) -o $@

all: $(NAME)

$(NAME): $(OBJ) $(GET_NEXT_LINE_OBJ) $(FT_PRINTF_OBJ)
	@ar rcs $(NAME) $(OBJ) $(GET_NEXT_LINE_OBJ) $(FT_PRINTF_OBJ)
	@echo "Library $(NAME) created."

bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)
	@echo "Bonus object added to $(NAME)."

clean:
	@rm -f $(OBJ) $(BONUS_OBJ) $(GET_NEXT_LINE_OBJ) $(FT_PRINTF_OBJ)
	@echo "Removed all object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned Library $(NAME) and all object files."

re: fclean all

.PHONY: all clean fclean re bonus