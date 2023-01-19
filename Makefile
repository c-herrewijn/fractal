NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRCS = main.c img.c mandelbrot.c grid.c color.c
OBJS = $(SRCS:.c=.o)
LIBFTDIR = libft
LIBFTNAME = libft.a
MINILIBX_DIR = mlx
MINILIBX_NAME = libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME) $(MINILIBX_DIR)/$(MINILIBX_NAME)
	$(CC) $(FLAGS) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME) $(MINILIBX_DIR)/$(MINILIBX_NAME) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFTDIR)/$(LIBFTNAME):
	cd $(LIBFTDIR) ; make bonus

$(MINILIBX_DIR)/$(MINILIBX_NAME):
	cd $(MINILIBX_DIR) ; make

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) ; make clean
	cd $(MINILIBX_DIR) ; make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) ; make fclean

re: fclean all

.PHONY: all clean fclean re
