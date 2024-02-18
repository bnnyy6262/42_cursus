# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medalgic <medalgic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:18:49 by medalgic          #+#    #+#              #
#    Updated: 2023/10/16 19:36:52 by medalgic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
all: 
	gcc $(FALG) server.c -o server
	gcc $(FALG) client.c -o client

clean: clean
	rm -rf server client
fclean: fclean
	make clean
re: re
	make clean
	make
.PHONY: clean re fclean