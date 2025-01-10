NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
RM = rm -f

SRCS = utils/ft_atoi.c \
       utils/ft_isdigit.c \
       utils/ft_calloc.c \
       utils/ft_bzero.c \
       utils/ft_split.c \
       utils/ft_strdup.c \
       utils/ft_strjoin.c \
       utils/ft_strlcpy.c \
       utils/ft_strlen.c \
       utils/ft_strncmp.c \
       utils/ft_substr.c \
       utils/errors.c \
       utils/validate_inputs.c \
       utils/stack_utils.c \
       moves/sa.c \
       moves/pb.c \
       moves/pa.c \
       moves/rrr.c \
       moves/rrb.c \
       moves/rra.c \
       moves/rr.c \
       moves/rb.c \
       moves/ra.c \
          sortings/get_big_small.c\
	   sortings/sorting.c \
	   sortings/sorting_utils.c \
	   sortings/sorting_utils2.c \
	   sortings/push_cheapest.c \
	   sortings/check_cheapest.c \
	   sortings/targets.c \
       push_swap.c

OBJS = $(SRCS:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)
	@echo "ok"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "fully cleaned"

re: fclean all

.PHONY: all clean fclean re
