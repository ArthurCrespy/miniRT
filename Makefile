# Variables

NAME		=miniRT


LIBFT_DIR	=libft/

LIBFT_FILE	=libft.a

LIBFT		=$(LIBFT_DIR)$(LIBFT_FILE)

MLX_DIR		=minilibx-linux/

MLX_FILE	=libmlx.a

MLX			=$(MLX_DIR)$(MLX_FILE)

MLX_FLAGS	=-lX11 -lXext

SRC_DIR		=srcs/

OBJ_DIR		=objs/

INC_DIR		=includes/

INCS 		= $(LIBFT) includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall
RM = rm -rf
AR = ar rc
RANLIB = ranlib

SRC_FILES = main\
			hooks\
			free


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES) $(SRC_FILES_THREAD)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES) $(SRC_FILES_THREAD)))

all: $(NAME)

thread: $(NAME_THREAD)

$(LIBFT):
	git submodule update --init
	make all -C $(LIBFT_DIR)

$(MLX):
	make all -C $(MLX_DIR)

$(NAME):	$(LIBFT) $(OBJS) $(MLX)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -lm


$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
				$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
			-mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re thread