NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

OUT_DIR			=	build
SRCS			=	src/ft_push.c src/ft_reverse_rotate.c src/ft_rotate.c src/ft_solver.c src/ft_stack.c src/ft_utils.c src/push_swap.c src/ft_simple_solvers.c src/ft_solve_lots.c
OBJS			=	$(SRCS:%.c=$(OUT_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)

$(OBJS): $(OUT_DIR)/%.o: $(SRC_DIR)/%.c
					mkdir -p $(@D)
					@echo "Compiling $<"
					$(CC) $(CFLAGS) -Iincludes -c $< -o $@

bonus:				all

$(NAME):			$(LIBFT)
					$(CC) $(CFLAGS) -Iincludes -Ilibft -Llibft -lft $(SRCS) -o $(NAME)

$(LIBFT):
					make -C $(LIBFT_PATH) bonus
					cp	$(LIBFT) ./$(NAME)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) ${OBJS}

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

linux:
					make -C $(LIBFT_PATH) bonus so
					cp $(LIBFT_PATH)/libft.so .
					@gcc $(SRCS) -L libft -lft -Wl,-rpath=libft/ -o push_swap -g -I includes -I libft

test:				${OUT_DIR}
					@make -C $(LIBFT_PATH) bonus so
					@gcc -D PRINT=0 src/ft_push.c src/ft_reverse_rotate.c src/ft_rotate.c src/ft_solver.c src/ft_stack.c src/ft_utils.c src/tester.c src/ft_simple_solvers.c src/ft_solve_lots.c -L libft -fPIC -lft -Wl,-rpath=libft/ -o build/tester -g -I includes -I libft
					@./build/tester

retest:				fclean test

.PHONY:				all bonus clean fclean re libft test

${OUT_DIR}:
		mkdir -p ${OUT_DIR}
