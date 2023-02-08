NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRC_DIR = sources
SRCS = color.c event_handlers.c fractals.c grid.c img.c julia_validations.c julia.c main.c utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = libft
LIBFTNAME = libft.a
MINILIBX_DIR = mlx
MINILIBX_NAME = libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) $(MINILIBX_DIR)/$(MINILIBX_NAME)
	$(CC) $(FLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFTNAME):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(MINILIBX_DIR)/$(MINILIBX_NAME):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean	

re: fclean all

.PHONY: all clean fclean re
