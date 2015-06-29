##
## Makefile for makefile in /media/dwarfnet/DATA/REV/Malloc
## 
## Made by DwarfNet
## Login   <dwarfnet@epitech.net>
## 
## Started on  Thu Jun 18 16:09:09 2015 DwarfNet
## Last update Thu Jun 25 17:29:21 2015 DwarfNet
##

CC	= gcc

RM	= rm -f

CFLAGS	= -W -fPIC -Wall -Wextra -I./include/ -g3 ##-Werror

NAME	= libmy_malloc_i386-linux.so

SRC	= my_malloc.c \
	  my_structure.c \
	  my_error1.c \
	  my_list1.c \
	  my_list2.c \
	  realloc.c \
	  free.c \
	  show_alloc_mem.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
