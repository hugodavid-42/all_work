SRC =  ft_putchar.c ft_printf.c convert_hex.c\

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME) $(EXEC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean $(NAME)