# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 18:07:11 by kdumarai          #+#    #+#              #
#    Updated: 2017/12/15 18:07:17 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = genf

CFLAGS = -Wall -Werror -Wextra

SRCS = gen_file.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
