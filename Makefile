MINILIBX_MACOS_DIR = minilibx_macos
MINILIBX_MACOS = $(MINILIBX_MACOS_DIR)/libmlx.a

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(MINILIBX_MACOS_DIR)

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

MAIN_EXEC = fdf

all: $(MAIN_EXEC)

$(MAIN_EXEC): $(MAIN_OBJ) $(MINILIBX_MACOS) # $(CFLAGS) after CC
	$(CC) $(MAIN_OBJ) -L$(MINILIBX_MACOS_DIR) -lmlx -framework OpenGL -framework AppKit -o $(MAIN_EXEC)

%.o: %.c # $(CFLAGS) after CC
	$(CC) $(INCLUDES) -c $< -o $@

$(MINILIBX_MACOS):
	make -C $(MINILIBX_MACOS_DIR)

clean:
	rm -f $(MAIN_OBJ)
	make clean -C $(MINILIBX_MACOS_DIR)

fclean: clean
	rm -f $(MAIN_EXEC)
	rm -f $(MINILIBX_MACOS)

re: fclean all

e: clean fclean

.PHONY: all clean fclean re
