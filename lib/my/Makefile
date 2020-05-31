##
## EPITECH PROJECT, 2019
## Makefile_lib
## File description:
## Makefile_lib
##

SRC     =	my_putchar.c  			\
		my_strlen.c					\
		my_put_nbr.c				\
		my_strncpy.c				\
		my_putstr.c					\
		my_swap.c					\
		my_revstr.c					\
		my_isneg.c					\
		my_strcpy.c					\
		my_getnbr.c					\
		my_strcmp.c					\
		my_printf_s.c				\
		my_printf.c 				\
		my_convert_base.c			\
		find_index.c

OBJ       =	$(SRC:.c=.o)

NAME      =    	libmy.a

all:	$(NAME)

$(NAME):       	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:     clean all

.PHONY: all clean fclean re