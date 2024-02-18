NAME := so_long

CC := gcc
NORMINETTE := norminette

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := main.c map.c map_2.c map_reading.c graphics.c controls.c
GETNEXTLINE := gnl/get_next_line.c gnl/get_next_line_utils.c   
LIBFT := libft/ft_strlen.c libft/ft_strjoin.c
FTPRINTF := ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(FTPRINTF) $(LIBFT) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

norm:
	$(NORMINETTE) $(SOURCE) $(FTPRINTF) $(LIBFT) $(GETNEXTLINE) so_long.h
clean:
	rm -rf  so_long

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
.PHONY : all clean fclean re norm