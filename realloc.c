/*
** realloc.c for realloc in /home/dwarfnet/Desktop/REV/Malloc
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Tue Jun 23 21:54:48 2015 DwarfNet
** Last update Fri Jun 26 16:01:34 2015 DwarfNet
*/

#include "h_main.h"

t_list	*my_ptr_block(void * ptr, t_list *list)
{
  list = my_goto_start_list(list);
  while (list->next != NULL && ptr != list->ptr)
    list = list->next;
  if (list->next == NULL && ptr != list->ptr)
    return (NULL);
  return (list);
}

static t_list		*my_reduce_size(t_list *list, size_t size)
{
  t_list	*new;

  if (size > sizeof(t_list))
    {
      new = list->ptr + size;
      new->ptr = new + 1;
      new->size = list->size - sizeof(t_list) - size;
      new->free = 1;
      new->prev = list;
      new->next = list->next;
      list->next = new;
      list->size = size;
    }
  return (list);
}

static t_list		*my_new_free(t_list *list, size_t size)
{
  t_list	*ptr;

  ptr = NULL;
  list->free = 1;
  if ((ptr = my_get_static(ptr)) == NULL)
    if ((ptr = my_init_page()) == NULL)
      return (NULL);
  if ((ptr = my_get_free_block(ptr, size)) == NULL)
    return (NULL);
  ptr = my_set_size(ptr, size);
  ptr->free = 0;
  ptr->ptr = ptr + 1;
  if (list->size >= ptr->size)
    ptr->ptr =  memcpy(ptr->ptr, list->ptr, ptr->size);
  else
    ptr->ptr =  memcpy(ptr->ptr, list->ptr, list->size);
  my_set_static(ptr);
  return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
  t_list	*list;

  printf("\033[31mREALLOC :: %p :: %zu\033[0m\n", ptr, size);
  list = NULL;
  if ((list = my_get_static(list)) == NULL)
    list = my_init_page();
  if ((list = my_ptr_block(ptr, list)) == NULL)
    return (malloc(size));
  if (list->size >= size)
    list = my_reduce_size(list, size);
  else
    if ((list = my_new_free(list, size)) == NULL)
      return (NULL);
  my_set_static(list);
  return(list->ptr);
}
