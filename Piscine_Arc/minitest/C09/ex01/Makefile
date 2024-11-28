NAME = libft.a
SRCS_DIR = srcs
INCLUDES_DIR = includes
SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strcmp.c
INCLUDES = $(INCLUDES_DIR)/ft.h
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
