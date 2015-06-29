##
## Makefile for makefile in /media/dwarfnet/DATA/REV/Malloc
## 
## Made by DwarfNet
## Login   <dwarfnet@epitech.net>
## 
## Started on  Thu Jun 18 16:09:09 2015 DwarfNet
## Last update Mon Jun 29 14:54:43 2015 DwarfNet
##

CC	= gcc

RM	= rm -f

CFLAGS	= -fPIC -W -Wall -Wextra -Werror -I./include/ -g3

NAME	= libmy_malloc_$(HOSTTYPE).so

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
	ln -f -s libmy_malloc_$(HOSTTYPE).so libmy_malloc.so
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

lclean:	fclean
	$(RM) libmy_malloc.so

re:	lclean all

.PHONY:	all clean fclean lclean re
