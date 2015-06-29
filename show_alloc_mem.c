/*
** show_alloc_mem.c for malloc in /home/dwarfnet/Documents/REV/Malloc
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Wed Jun 24 11:08:37 2015 DwarfNet
** Last update Fri Jun 26 14:59:07 2015 DwarfNet
*/

#include "h_main.h"

void		show_alloc_mem()
{
  t_list	*list;

  list = NULL;
  list = my_get_static(list);
  printf("\033[36mbreak : %p\033[0m\n", sbrk(0));
  list = my_goto_start_list(list);
  list = list->next;
  while (list != NULL)
    {
      //      if (list->free == 0)
	printf("\033[33m%p :: %p - %p to %p: %zu octets\033[0m  \t%i\n", list, list->ptr, my_get_next_struct(list->size, list),list->next,  list->size, list->free);
      list = list->next;
    }
}
