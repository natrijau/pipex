CC=clang
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
HEADER=ft_printf.h
SOURCES= ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_unsigned.c ft_printf.c ft_hexa_MAJ.c ft_hexa_min.c ft_pointer_hexa.c ft_percent.c
OBJECTS=$(SOURCES:.c=.o) 

$(NAME): $(OBJECTS) 
	ar -rcs $(NAME) $(OBJECTS) 

all: $(NAME)

clean :
	rm -f $(OBJECTS) 

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
