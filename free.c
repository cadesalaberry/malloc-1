/*
** free.c for free in /home/dwarfnet/Documents/REV/Malloc
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Wed Jun 24 10:16:28 2015 DwarfNet
** Last update Fri Jun 26 16:03:17 2015 DwarfNet
*/

#include "h_main.h"

static t_list	*my_final_free(t_list *list)
{
  list = my_goto_start_list(list);
  while (list->next != NULL && list->free == 0)
    list = list->next;
  if (list->next == NULL && list->free == 1)
    {
      list = my_goto_start_list(list);
      brk(list);
      return (NULL);
    }
  return (list);
}

void	free(void *ptr)
{
    t_list	*list;

    printf("\033[33mFREE :: %p\033[0m\n", ptr);
    list = NULL;
    if ((list = my_get_static(list)) == NULL)
      return;
    if ((list = my_ptr_block(ptr, list)) == NULL)
      return;
    list->free = 1;
    if ((list = my_final_free(list)) == NULL)
      return;
    my_set_static(list);
    return;
}
