RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

HEADERS = -I./include -I$(LIBMLX_PATH)/include
SRC = main_fdf.c \
		src/fdf_parser/parse_fdf.c \
		src/fdf_parser/allocate_matrix.c \
		src/fdf_parser/get_width.c \
		src/fdf_parser/row_parser.c \
		src/drawing/draw_line.c \
		src/drawing/modify_coordinates.c \
		src/drawing/setup.c \
		src/drawing/render_grid.c \
		src/drawing/isometric_projection.c \
		src/color_utils/colors.c \
		src/utils/graphics_utils.c \
		src/utils/setup_hooks.c \
		src/utils/controls.c \
		src/utils/memory_utils.c \
		src/utils/math_utils.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

LIBMLX_PATH = ./MLX42
LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBFT) $(LIBMLX) -o $(NAME)
	@echo "$(GREEN)✓ Project $(NAME) created.$(NC)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(LIBMLX):
	@cmake -S $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build -DDEBUG=1 -DGLFW_FETCH=0
	@cmake --build $(LIBMLX_PATH)/build -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(LIBMLX_PATH)/build
	@echo "Object files and MLX42 build files cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(YELLOW)✓ Project $(NAME) and all files cleaned.$(NC)"

re: fclean all

.PHONY: all clean fclean re
