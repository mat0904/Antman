##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-adrien.audiard
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/antman.c	\
		src/file_info.c	\
		src/huffman/huffman.c	\
		src/huffman/free.c	\
		src/huffman/display.c	\
		src/huffman/compress_txt.c	\
		src/huffman/node_quicksort.c	\
		src/huffman/init_text_structure.c	\
		src/huffman/array_manipulation.c	\
		src/huffman/binary_manipulation.c	\
		src/huffman/huffmantree_manipulation.c	\
		src/huffman/huffman_binary_manipulation.c	\
		src/html/compress_html.c	\
		src/html/write_src_and_cmp.c	\
		src/ppm/compress_ppm.c	\
		src/ppm/init_buffer.c	\
		src/ppm/init_pixel_struct.c	\
		src/ppm/print_result_ppm.c

OBJ	=	$(SRC:.c=.o)
EXE	=	antman
CC	=	gcc
CFLAGS	=
LDFLAGS	=	-L./lib/my -lmy

all:	$(EXE)

%.o	: 	%.c
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
