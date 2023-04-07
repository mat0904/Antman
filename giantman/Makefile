##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-adrien.audiard
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/giantman.c	\
		src/file_info.c	\
		src/huffman/free.c	\
		src/huffman/node_quicksort.c	\
		src/huffman/create_huffman_tree.c	\
		src/huffman/huffman.c	\
		src/huffman/decompress_txt.c	\
		src/huffman/extract_text.c	\
		src/huffman/binary_manipulation.c    \
		src/html/decompress_html.c	\
		src/ppm/decompress_ppm.c	\
		src/ppm/init_buffer.c

OBJ	=	$(SRC:.c=.o)
EXE	=	giantman
CC	=	gcc
FLAGS	=
LDFLAGS	=	-L./lib/my -lmy

all:	$(EXE)

%.o :	%.c
		$(CC) -o $@ -c $< $(CFLAGS)

$(EXE):	$(OBJ)
		@make -C ./lib/my
		$(CC) -o $(EXE) $(OBJ) $(LDFLAGS)

clean:
		@make -C ./lib/my clean
		rm -rf $(OBJ)

fclean:	clean
		@make -C ./lib/my fclean
		rm -rf $(EXE)

re:	fclean all
	@make -C ./lib/my re
