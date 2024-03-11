NAME	 = pipex
CFLAGS	 = -Wall -Wextra -Werror -g
LIBFT    =  ./libft/
PRINTF   = ./printf/
PRINTF_A = $(PRINTF)libftprintf.a
LIBFT_A  = $(LIBFT)libft.a
SRCS	 = main.c check_arg.c free.c get_path.c open_files.c init_cmd_and_options.c main_utils.c
OBJS	 = ${SRCS:.c=.o}

%.o: %.c 
	clang $(CFLAGS) $< -c -o $@ 

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	make -C $(PRINTF)
	clang -o $(NAME) $(OBJS) $(LIBFT_A) $(PRINTF_A)

clean:
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)
	rm -rf $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
