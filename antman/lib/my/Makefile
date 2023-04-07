##
## EPITECH PROJECT, 2022
## B-PSU-100-LYN-1-1-bsmyls-mathieu.borel
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_string.c	\

OBJ	=	$(SRC:.c=.o)

EXE	=	libmy.a

all:	$(EXE)

%.o:	%.c
		$(CC) -o $@ -c $<

$(EXE):	$(OBJ)
		ar rc $@ $(OBJ)

clean:
		@rm -rf $(OBJ)

fclean:	clean
		rm -rf $(EXE)

re:	fclean all
