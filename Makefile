NAME = push_swap
CFLAGS = -Wall -Werror -Wextra

INC = ./includes/push_swap.h
SRCS = $(wildcard srcs/*.c)
LIBFT = libft/

# Colors

DEFAULT = \033[0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all : $(NAME)

$(NAME) : $(SRCS) $(INC) Makefile
	@make --no-print-directory -C $(LIBFT)
	@cp $(LIBFT)libft.a .
	@cc $(CFLAGS) $(SRCS) libft.a -o $@

clean :
	@rm -f $(OBJS)
	@make clean --no-print-directory -C $(LIBFT)
fclean :
	@rm -f $(NAME) libft.a
	@make fclean --no-print-directory -C $(LIBFT)

re : clean all

.PHONY: all clean fclean re
