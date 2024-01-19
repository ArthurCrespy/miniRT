# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2024/01/16 20:30:12 by dkeraudr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := miniRT

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

SRC_DIR     := srcs
SRCS := \
			args/args_check.c \
			data/data_free.c \
			data/data_initialize.c \
			events/event_key.c \
			events/event_resize.c \
			file/file_check.c \
			file/file_save.c \
			mlx/mlx_exit.c \
			mlx/mlx_initialize.c \
			mlx/mlx_loop.c \
			mlx/mlx_render.c \
			parsing/parsing.c \
			utils/ft_calloc.c \
			utils/ft_exit.c \
			utils/ft_free.c \
			utils/ft_gnl.c \
			utils/ft_put.c \
			utils/ft_str.c \
			main.c

SRCS := ${SRCS:%=${SRC_DIR}/%}

OBJ_DIR     := .objs
OBJS := ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

INCL_DIR     := includes

MLX_DIR     := minilibx-linux
MLX         := $(MLX_DIR)/libmlx.a

OS_NAME := $(shell uname -s | tr A-Z a-z)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g

ifeq ($(OS_NAME),linux)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR)
endif
ifeq ($(OS_NAME),darwin)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR) -I/usr/X11/include
	CFLAGS      := -Wall -Wextra -g
endif

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p ${@D}

all: ${NAME}

${LIBFT}:
	git submodule update --init
	${MAKE} all -C ${LIBFT_DIR}

${MLX}:
	git submodule update --init
	${MAKE} all -C ${MLX_DIR}

${NAME}: ${MLX} ${LIBFT} ${OBJS}
	${CC} ${OBJS} ${LIBFT} ${MLX_LINK} -o ${NAME}
	${info EXECUTABLE CREATED: ${NAME}}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} -c -o $@ $<
	${info OBJECT CREATED: $@}

clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT_DIR}
	make clean -C ${MLX_DIR}
	${info REMOVED OBJECTS: ${OBJS}}

fclean: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_DIR}
	${info REMOVED EXECUTABLES: ${NAME}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: clean fclean re
.SILENT: ${NAME} ${SRCS} ${OBJS} ${LIBFT} all clean fclean re