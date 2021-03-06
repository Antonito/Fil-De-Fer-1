##
## Makefile for fdf1 in /home/bache_a/Infographie/gfx_fdf1
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Nov  6 13:26:38 2015 Antoine Baché
## Last update Sun Mar 13 08:32:05 2016 Antoine Baché
##

SRC=	src/main.c \
	src/tekpixel.c \
	src/tekline.c \
	src/tekllproject.c \
	src/filereader.c \
	src/my_square.c \
	src/my_getnbr.c \
	src/my_putchar.c \
	src/my_putstr.c \
	src/my_strcmp.c \
	src/my_setline.c \
	src/vertical_lines.c \
	src/my_escape.c

NAME=	fdf1

CC=	gcc -W -Wall -Werror -ansi -pedantic

RM=	rm -f

LIB=	-L/usr/local/lib \
	-L/home/${USER}/.froot/lib      \
	-I/home/${USER}/.froot/include  \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm

OBJ=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
