NAME = cub3d
SRC = main.c
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re ext mlx_check mlx_clone mlx_build

all: mlx_check $(NAME)

mlx_clone:
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "MiniLibX absente, clonage depuis GitHub..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi

mlx_build:
	@if [ ! -f $(MLX_LIB) ]; then \
		echo "Compilation MiniLibX..."; \
		$(MAKE) -C $(MLX_DIR); \
	fi

mlx_check: mlx_clone mlx_build

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean:
	@echo "Nettoyage fichiers objets..."
	@rm -f *.o

fclean: clean
	@echo "Suppression du binaire $(NAME)..."
	@rm -f $(NAME)
	@if [ -d $(MLX_DIR) ]; then \
		echo "Suppression complète de MiniLibX..."; \
		rm -rf $(MLX_DIR); \
	fi

re: fclean all

ext:
	@if [ -d $(MLX_DIR) ]; then \
		echo "Recompilation forcée MiniLibX..."; \
		$(MAKE) -C $(MLX_DIR) clean; \
		$(MAKE) -C $(MLX_DIR); \
	else \
		$(MAKE) mlx_clone mlx_build; \
	fi
