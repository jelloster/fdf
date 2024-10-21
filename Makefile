# ----------FLAGS------------

FLAGS		:=	-Wall -Wextra -Werror -o2
DEBUG_FLAGS	:=	-g
SANITIZE_FLAGS	:=	-g -fsanitize=address

# ------- COMPILER ----------

CC		:=	cc

# ------ SOURCE FILES -------

SRC_PATH	:= ./srcs/

SRC_FILES	:=	main.c			\
			parsing.c 			\
			memory_functions.c 	\
			key_hook.c 			\
			color_functions.c 	\
			fdf.c 				\
			draw_line.c 		\
			math_utils.c 		\
			move.c 				\
			zoom.c 				\

PATHED_SRC	:= $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_FILES	:=	$(PATHED_SRC:.c=.o)
NAME		:=	fdf
LIBFT		:=	libft/libft.a

# ---------- MLX42 ----------

LIBMLX		:=	MLX42/build/libmlx42.a
MLX		:=	./MLX42
HEADERS		:=	-I $(MLX)/include -I libft/inc -I inc
LIBS            :=  $(LIBMLX) -ldl -lglfw -pthread -lm

# -------------RULES--------------

$(NAME): $(OBJ_FILES) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJ_FILES) $(LIBFT) $(LIBS) -o $@

$(LIBMLX): mlx_clone
	@if [ ! -f "$(LIBMLX)" ]; then \
		cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4; \
	fi

$(OBJ_FILES): %.o : %.c $(LIBMLX)
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT):
	@make -C libft

# ----------- PHONIES ------------

.PHONY: mlx_clone
mlx_clone:
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX); \
	fi

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) 

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	@rm -rf $(MLX)/build

.PHONY: bonus
bonus : all

.PHONY: re
re: fclean all

.PHONY: mc
mc: all clean

.PHONY: debug
debug: FLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: sanitize
sanitize: FLAGS += $(SANITIZE_FLAGS)
sanitize: re
