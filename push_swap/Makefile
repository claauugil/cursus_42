NAME = push_swap

SRC = utils/errors.c \
	  utils/ft_atoi.c \
      utils/ft_bzero.c \
      utils/ft_isdigit.c \
      utils/ft_split.c \
      utils/ft_strdup.c \
      utils/ft_strjoin.c \
      utils/ft_strlcpy.c \
      utils/ft_strlen.c \
      utils/ft_strncmp.c \
      utils/ft_substr.c \
      utils/ft_calloc.c \
      utils/stack_utils.c \
      utils/validate_inputs.c \
	  	sorting/check_cheapest.c \
	  	sorting/get_big_small.c \
	 	sorting/push_cheapest.c \
	  	sorting/sorting_utils.c \
		sorting/sorting_utils2.c \
	  	sorting/sorting.c \
	 	sorting/targets.c \
	  movements/pa.c \
	  movements/pb.c \
	  movements/ra.c \
	  movements/rb.c \
	  movements/rr.c \
	  movements/rra.c \
	  movements/rrb.c \
	  movements/rrr.c \
	  movements/sa.c \
	  movements/sb.c \
	  push_swap.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I./

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
