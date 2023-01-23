NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRCS = main.c img.c fractals.c grid.c color.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = libft
LIBFTNAME = libft.a
MINILIBX_DIR = mlx
MINILIBX_NAME = libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) $(MINILIBX_DIR)/$(MINILIBX_NAME)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME) $(MINILIBX_DIR)/$(MINILIBX_NAME) -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFTNAME):
	cd $(LIBFT_DIR) ; make bonus

$(MINILIBX_DIR)/$(MINILIBX_NAME):
	cd $(MINILIBX_DIR) ; make

clean:
	rm -rf $(OBJ_DIR)
	cd $(LIBFT_DIR) ; make clean
	cd $(MINILIBX_DIR) ; make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) ; make fclean

re: fclean all

.PHONY: all clean fclean re
