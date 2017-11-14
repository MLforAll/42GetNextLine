# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:07:31 by kdumarai          #+#    #+#              #
#    Updated: 2017/11/14 20:07:04 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	make -C ../Libft && make clean -C ../Libft
	clang $(CFLAGS) -I ../Libft -o get_next_line.o -c get_next_line.c
	clang $(CFLAGS) -I ../Libft -o main.o -c main.c
	clang -o $(NAME) main.o get_next_line.o -I ../Libft -L ../Libft -lft

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
