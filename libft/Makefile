NAME			:=	libft.a
CC				:=	cc 
FLAGS 			:=	-Wall -Wextra -Werror -g

INC_DIR			:=	./inc/
INC				:=	-I $(INC_DIR)

# ----- FILES ------

# PATHS

SRC_PATH		:= 	./srcs/
L_LIST_PATH 	:=	./srcs/linked_list/
FT_PRINTF_PATH	:=	./srcs/ft_printf/
GNL_PATH		:=	./srcs/get_next_line/

# C FILES

MAIN_FILES 		:=	ft_isascii.c ft_memcpy.c ft_split.c ft_strlcpy.c		\
				ft_strtrim.c ft_atoi.c ft_isdigit.c ft_memmove.c			\
				ft_memset.c ft_strdup.c ft_strmaapi.c ft_tolower.c 			\
				ft_calloc.c ft_itoa.c ft_putendl_fd.c ft_striteri.c			\
				ft_strncmp.c ft_toupper.c ft_isalnum.c ft_memchr.c			\
				ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isalpha.c		\
				ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c		\
				ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_bzero.c			\
				ft_isprint.c ft_substr.c


L_LIST_SRC		:= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c	\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c	\
				ft_lstmap.c

FT_PRINTF_SRC	:=	ft_printf.c buf_functions.c conversion_functions.c

GNL_SRC			:=	get_next_line.c	get_next_line_utils.c

# PATHED FILES

P_MAIN			:=	$(addprefix $(SRC_PATH), $(MAIN_FILES))
P_L_LIST		:=	$(addprefix $(L_LIST_PATH), $(L_LIST_SRC))
P_FT_PRINTF		:=	$(addprefix $(FT_PRINTF_PATH), $(FT_PRINTF_SRC))
P_GNL			:=	$(addprefix $(GNL_PATH), $(GNL_SRC))

# COMBINED FILES

SRC_FILES		:=	$(P_MAIN) $(P_L_LIST) $(P_FT_PRINTF) $(P_GNL)
OBJ_FILES		:=	$(SRC_FILES:.c=.o)

# -------------RULES-----

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_FILES): %.o : %.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@

# ----------- PHONIES ------------

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ_FILES)

.PHONY: fclean
fclean: clean
	rm -f libft.a

.PHONY: re
re: fclean all
