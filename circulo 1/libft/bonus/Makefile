# Archivos fuente
SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c\
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_split.c \

BSRC = ft_lstnew_bonus.c \
       ft_lstadd_front_bonus.c \
       ft_lstsize_bonus.c \
       ft_lstlast_bonus.c \
       ft_lstadd_back_bonus.c \
       ft_lstdelone_bonus.c \
       ft_lstclear_bonus.c \
       ft_lstiter_bonus.c \
# Nombre de la biblioteca
NAME = libft.a

# Archivos objeto
OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

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

# Regla para el bonus
bonus: $(OBJ) $(BOBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BOBJ)

# Regla para compilar archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos objeto
clean:
	rm -f $(OBJ) $(BOBJ)

# Regla para limpiar completamente
fclean: clean
	rm -f $(NAME)

# Regla para recompilar
re: fclean all bonus

# Declarar las reglas como 'phony'
.PHONY: clean fclean all re bonus
