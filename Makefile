NAME = push_swap
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/
INC = ./includes/push_swap.h
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)

INC_BONUS = bonus/checker.h
SRCS_BONUS = $(wildcard bonus/*.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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

bonus : clean fclean $(SRCS_BONUS) $(INC_BONUS) Makefile
	@make --no-print-directory -C $(LIBFT)
	@cp $(LIBFT)libft.a .
	@cc $(CFLAGS) $(SRCS_BONUS) libft.a -o push_swap_bonus

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@make clean --no-print-directory -C $(LIBFT)

fclean :
	@rm -f $(NAME) push_swap_bonus libft.a
	@make fclean --no-print-directory -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
