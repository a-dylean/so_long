NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
INCLUDES = -I includes -I libft -I libft/ft_printf -I mlx
SRC = src/main.c  src/image_rendering.c src/parsing.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
PRINTF = libft/ft_printf/ft_printf.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(LIBFT) $(PRINTF) $(MLX_LIB) $(OBJ)
#$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L libft -lft -L libft/ft_printf -lftprintf $(MLX_FLAGS)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C libft/ft_printf

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	make clean -C libft
	make clean -C libft/ft_printf
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C libft/ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re