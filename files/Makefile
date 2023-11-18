# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 14:54:39 by acrespy           #+#    #+#              #
#    Updated: 2023/01/16 15:01:53 by acrespy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := miniRT

SRC_DIR     := srcs
SRCS := \
			main.c

SRCS := ${SRCS:%=${SRC_DIR}/%}

OBJ_DIR     := .objs
OBJS := ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

INCL_DIR     := includes

MLX_DIR     := mlx

OS_NAME := $(shell uname -s | tr A-Z a-z)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g

ifeq ($(OS_NAME),linux)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
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

all: git miniLibX ${NAME}

git:
	@if [ -d "$(MLX_DIR)" ]; then \
		${MAKE} pull_mlx; \
	else \
		${MAKE} clone_mlx; \
	fi

clone_mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ${MLX_DIR}

pull_mlx:
	git -C ${MLX_DIR} pull

miniLibX: ${MLX_DIR}
	${MAKE} -C ${MLX_DIR}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${MLX_LINK} -o ${NAME}
	${info EXECUTABLE CREATED: ${NAME}}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${MLX_INCL} -c -o $@ $<
	${info OBJECT CREATED: $@}

miniLibXClean:
	${MAKE} clean -C ${MLX_DIR}

clean: miniLibXClean
	${RM} ${OBJS}
	${info REMOVED OBJECTS: ${OBJS}}

fclean: clean
	${RM} ${NAME}
	${info REMOVED EXECUTABLES: ${NAME}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: miniLibX clone_mlx clean miniLibXClean fclean re
.SILENT: ${NAME} ${SRCS} ${OBJS} clean fclean re