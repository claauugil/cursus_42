NAME = push_swap

SRC = 

OBJ = $(SRC:.c=.o)

INCLUDES = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "ok"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Completed compilation"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "full clean done"

re: fclean all

.PHONY: clean fclean all re
