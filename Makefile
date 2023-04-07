##
## EPITECH PROJECT, 2023
## B-CPE-110-LYN-1-1-antman-adrien.audiard
## File description:
## Makefile
##

all:	exec

exec:
		@make -C ./antman
		@make -C ./giantman

clean:
		@make -C ./antman clean
		@make -C ./giantman clean

fclean: clean
		@make -C ./antman fclean
		@make -C ./giantman fclean

re:	fclean all
