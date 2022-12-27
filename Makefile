NAME = fractol
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFTDIR = libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	$(CC) $(FLAGS) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFTDIR)/$(LIBFTNAME):
	cd $(LIBFTDIR) ; make bonus

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) ; make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) ; make fclean

re: fclean all
