SRCS= errors.c \
	  event_handler.c \
	  fractol.c \
	  init.c \
	  math_utils.c \
	  rendering.c \
	  str_utils.c \

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

INCLUDES = fractol.h

all: $(NAME)
	@echo "OK"

$(NAME) : $(OBJS)
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "compilation completed"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@rm -f $(OBJS)
	@echo "cleaned"
fclean: clean
	@rm -f $(NAME)
	@echo "fully clean"
re: fclean all

.PHONY: clean fclean all re
