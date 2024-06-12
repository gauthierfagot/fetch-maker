##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c	\
		src/fetch_command.c	\
		src/fetch_hardware.c	\
		src/fetch_memory.c	\
		src/fetch_usr_info.c	\
		src/fetch_window_info.c	\
		src/format_arguments.c	\
		src/useful_functions.c

OBJ     =	$(SRC:.c=.o)

NAME    =	fetch

CFLAGS	+= 	-Wall -Wextra

CPPFLAGS	+=	-iquote./include

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re style
