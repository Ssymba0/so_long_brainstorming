NAME = so_long.a
SRCS =	check_map.c\
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
		

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit

CC = gcc

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) -o so_long
all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all