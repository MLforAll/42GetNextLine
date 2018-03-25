# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 17:16:02 by kdumarai          #+#    #+#              #
#    Updated: 2017/12/08 17:32:46 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

fprojName = gnl_simple_shell
sprojName = gnl_login

CFLAGS = -Wall -Werror -Wextra

SRCS = gnl_ex_shell.c
SRCSS = gnl_ex_login.c

OBJS = $(SRCS:%.c=%.o)
OBJSS = $(SRCSS:%.c=%.o)

all: $(fprojName) $(sprojName)

pre:
	make -C ../Libft
	gcc -c ../Get_Next_Line/get_next_line.c

$(fprojName): pre
	gcc $(CFLAGS) -c $(SRCS)
	gcc -o $(fprojName) $(OBJS) get_next_line.o -L ../Libft -lft

$(sprojName): pre
	gcc -c $(SRCSS)
	gcc -o $(sprojName) $(OBJSS) get_next_line.o -L ../Libft -lft

clean:
	rm -f $(OBJS) $(OBJSS) get_next_line.o

fclean: clean
	rm -f $(fprojName) $(sprojName)

re: fclean all

.PHONY: all clean fclean re
