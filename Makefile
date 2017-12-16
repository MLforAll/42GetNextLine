# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:07:31 by kdumarai          #+#    #+#              #
#    Updated: 2017/12/15 18:33:17 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): get_next_line.c get_next_line.h main.c
	make -C libft
	clang $(CFLAGS) -I ../Libft -o get_next_line.o -c get_next_line.c -g3
	clang $(CFLAGS) -I ../Libft -o main.o -c main.c -g3
	clang -o $(NAME) main.o get_next_line.o -I ../Libft -L ../Libft -lft -g3

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
