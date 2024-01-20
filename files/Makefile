# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2024/01/16 20:30:12 by acrespy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := miniRT

SRC_DIR     := srcs
SRCS		:= \
				main.c \
				args/args_check.c \
				data/data_free.c \
				data/data_initialize.c \
				double/double_comparaisons.c \
				events/event_key.c \
				events/event_resize.c \
				file/file_check.c \
				file/file_save.c \
				mlx/mlx_exit.c \
				mlx/mlx_initialize.c \
				mlx/mlx_loop.c \
				mlx/mlx_render.c \
				parsing/parsing.c \
				point/point_comparaisons.c \
				point/point_operations.c \
				point/point_scalar.c \
				point/point_vector_operations.c \
				utils/ft_calloc.c \
				utils/ft_exit.c \
				utils/ft_free.c \
				utils/ft_gnl.c \
				utils/ft_put.c \
				utils/ft_str.c \
				vector/vector_comparaisons.c \
				vector/vector_create.c \
				vector/vector_functions.c \
				vector/vector_operations.c \
				vector/vector_point_operations.c \
				vector/vector_scalar.c \

SRCS		:= ${SRCS:%=${SRC_DIR}/%}

OBJ_DIR		:= .objs
OBJS		:= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

INCL_DIR	:= includes

LIBFT_DIR	:= libft
LIBFT		:= ${LIBFT_DIR}/libft.a

MLX_DIR		:= mlx

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p ${@D}

OS_NAME		:= $(shell uname -s | tr A-Z a-z)

ifeq ($(OS_NAME),linux)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR)
endif
ifeq ($(OS_NAME),darwin)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR) -I/usr/X11/include
	CFLAGS		:= -Wall -Wextra -g
endif

all: git miniLibX ${NAME}

git:
	@if [ -d "$(MLX_DIR)" ]; then \
		${MAKE} pull_mlx; \
	else \
		${MAKE} clone_mlx; \
	fi

clone_mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ${MLX_DIR}
	${info VERSION CONTROL: ${MLX_DIR} cloned}

pull_mlx:
	git -C ${MLX_DIR} pull
	${info VERSION CONTROL: ${MLX_DIR} up to date}

miniLibX: ${MLX_DIR}
	${MAKE} -C ${MLX_DIR}

${LIBFT}:
	git submodule update --init
	make all -C ${LIBFT_DIR}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${OBJS} ${LIBFT} ${MLX_LINK} -lm -o ${NAME}
	${info EXECUTABLE CREATED: ${NAME}}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} -c $< -o $@
	${info OBJECT CREATED: $@}

miniLibXClean:
	${MAKE} clean -C ${MLX_DIR}

libftClean:
	${MAKE} clean -C ${LIBFT_DIR}

fcleanLibft:
	${MAKE} fclean -C ${LIBFT_DIR}

clean: miniLibXClean libftClean
	${RM} ${OBJS}
	${RM} -r ${OBJ_DIR}
	${info REMOVED OBJECTS: ${OBJS}}

fclean: clean fcleanLibft
	${RM} ${NAME}
	${info REMOVED EXECUTABLES: ${NAME}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: miniLibX clone_mlx clean miniLibXClean fclean re
.SILENT: ${NAME} ${SRCS} ${OBJS} all miniLibX git clone_mlx pull_mlx clean fclean re