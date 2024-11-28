#!/bin/bash

LIBRARY_NAME="libft.a"

rm -f $LIBRARY_NAME

cc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

ar rcs $LIBRARY_NAME *.o

rm -f *.o

