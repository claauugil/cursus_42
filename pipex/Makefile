SRC = pipex.c \
	  pipex_utils.c

NAME = pipex

OBJ = $(SRC: .c= .o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	cd libft && $(MAKE);
	$(CC) $(CFLAGS) $(OBJ) -L ./libft -lft-o $(NAME)

clean:
	cd libft && $(MAKE) clean
	rm -f $(OBJ)
fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
re: fclean all

