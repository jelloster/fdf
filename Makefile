# ----------FLAGS------------
FLAGS			:=	-Wall -Wextra -Werror
DEBUG_FLAGS		:=	-g
SANITIZE_FLAGS	:=	-g -fsanitize=address

CC				:=	cc

SRC_FILES		:=	main.c error_functions.c parsing.c memory_functions.c
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
NAME			:=	fdf
LIBFT			:=	libft/libft.a

LIBMLX			:=	MLX42/build/libmlx42.a
MLX				:=	./MLX42
HEADERS			:=	-I $(MLX)/include -I $(LIBFT)/inc

LIBS            :=  $(LIBMLX) -ldl -lglfw -pthread -lm

# -------------RULES--------------

$(NAME): $(OBJ_FILES) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJ_FILES) $(LIBFT) $(LIBS) -o $@

$(OBJ_FILES): %.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT):
	@make -C libft

$(LIBMLX):
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

# ----------- PHONIES ------------

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES) 

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	@rm -rf $(MLX)/build

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
