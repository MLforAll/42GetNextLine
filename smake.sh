#!/bin/sh

CFLAGS="-Wall -Werror -Wextra"

clang $CFLAGS -I ../Libft -o get_next_line.o -c get_next_line.c -g3
clang $CFLAGS -I ../Libft -o smain.o -c smain.c -g3
clang -o stest_gnl smain.o get_next_line.o -I ../Libft -L ../Libft -lft -g3
rm smain.o
