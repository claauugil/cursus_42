# Archivos fuente
SRC = ft_strlcpy.c \
      ft_strlen.c  \
      ft_strncmp.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_split.c \
      ft_calloc.c \
      ft_bzero.c \

# Nombre de la biblioteca
NAME = libft.a

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Compilador y opciones
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Comando para crear la biblioteca
AR = ar
ARFLAGS = rcs

# Regla principal
all: $(NAME)

# Regla para crear la biblioteca
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# Regla para compilar archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos objeto
clean:
	rm -f $(OBJ)

# Regla para limpiar completamente
fclean: clean
	rm -f $(NAME)

# Regla para recompilar
re: fclean all

# Declarar las reglas como 'phony'
.PHONY: clean fclean all re
