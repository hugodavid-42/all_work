SRC =  get_next_line_utils.c get_next_line.c main.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
EXEC = prog

all: $(EXEC)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

$(EXEC): $(OBJ)
	cc $(CFLAGS) -o $(EXEC) main.o
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean $(NAME)