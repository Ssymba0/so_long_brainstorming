NAME = so_long.a
srcs =	check_map.c\
		draw_map.c\
		get_fd.c\
		get_map.c\
		get_next_line_utils.c\
		get_next_line.c\
		init_map.c\
		init_mlx.c\
		main.c\
		move.c\
		moves.c\
		read_map.c\
		

OBJS = $(srcs:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

NAME = $(OBJS)
	ar -rc $(NAME) $(OBJS)

all: $(NAME)

clean