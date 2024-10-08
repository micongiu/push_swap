NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -g -I./include -O2

SRCS = ./src/push_swap.c ./src/ft_error_and_free.c ./src/ft_init.c ./src/ft_quick_sort.c ./src/ft_sort_all.c ./src/ft_utility_0.c ./src/ft_utility_1.c \
	./src/move_push.c ./src/move_reverse_rotate.c ./src/move_rotate.c ./src/move_swap.c
SRC_DIRS = ./src
OBJS = ${SRCS:.c=.o}

PRINTF		:= ft_printf/libftprintf.a
LIBFT		:= libft/libft.a

GREEN		=\033[0;32m
RED			=\033[0;31m
BLUE		=\033[0;34m
COLOUR_END	=\033[0m

OBJ_DIR = ./obj
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,${SRCS})

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@mkdir -p ./obj/libft
	@mkdir -p ./obj/ft_printf
	@$(CC) -g -c $< -o $@;

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ft_printf/
	@$(MAKE) -C ./libft/
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)
	@echo "$(RED)EVERYTHING COMPILE!$(COLOUR_END)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -sC ft_printf/
	@make clean -sC libft/
	@rm -rf $(OBJS)
	@${RM} -r ${OBJ_DIR}
	@echo "$(GREEN)EVERYTHING HAS CLEAN!$(COLOUR_END)"

fclean: clean
	@rm -f $(NAME)
	@$(RM) -f $(PRINTF)
	@$(RM) -f $(LIBFT)
	@echo "$(BLUE)EVERYTHING HAS FCLEAN!$(COLOUR_END)"

re: fclean all
	@$(MAKE)

.PHONY: all clean fclean re