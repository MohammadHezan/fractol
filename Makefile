NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRCS = 	src/main.c \
		src/init.c \
		src/event.c \
		src/rendering.c \
		src/maths.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	
all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re