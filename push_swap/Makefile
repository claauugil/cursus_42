NAME = push_swap

SRC = utils/errors.c \
	  utils/ft_atoi.c \
	  utils/ft_is_digit.c \
	  utils/ft_split.c \
	  utils/ft_strdup.c \
	  utils/ft_strjoin.c \
	  utils/ft_strlcpy.c \
	  utils/ft_strlen.c \
	  utils/ft_strcmp.c \
	  utils/ft_substr.c \
	  utils/ft_calloc.c \

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
