# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 05:11:32 by medalgic          #+#    #+#              #
#    Updated: 2023/07/22 05:11:32 by medalgic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) ft_printf.o ft_printf_utils.o
clean:
	/bin/rm -f  ft_printf.o ft_printf_utils.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re