NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrcs

SRCS = 	srcs/main.c \
		srcs/init.c \
		srcs/event.c \
		srcs/rendering.c \
		srcs/maths.c \
		srcs/colors.c 

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -I$(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -O3 -c $< -o $@
	
all: $(MLX_LIB) $(NAME)


$(MLX_LIB): $(MLX_DIR)
	@make -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(NAME): $(OBJS) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re