/*
** my_list2.c for malloc in /home/dwarfnet/Documents/REV/Malloc
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Thu Jun 25 13:40:38 2015 DwarfNet
** Last update Fri Jun 26 17:10:13 2015 DwarfNet
*/

#include "h_main.h"

t_list		*my_fusion(t_list *keep, t_list *rmv)
{
  if (keep->free == 0 || rmv->free == 0 || keep == NULL || rmv == NULL)
    return (NULL);
  if (keep->next == NULL || keep->next != rmv)
    return (NULL);
  keep->size = keep->size + sizeof(t_list) + rmv->size;
  keep->next = rmv->next;
  if (rmv->next != NULL)
    rmv->next->prev = keep;
  keep->free = 1;
  if (keep->next != NULL && keep->next->free == 1)
    keep = my_fusion(keep, keep->next);
  return (keep);
}

t_list		*my_splitt(t_list *origin, size_t size)
{
  t_list	*new;

  if (origin->size > size + sizeof(t_list))
    {
      new = origin->ptr + size;
      new->free = 1;
      new->size = origin->size - size - sizeof(t_list);
      new->prev = origin;
      new->next = origin->next;
      new->ptr = new + 1;
      if (origin->next != NULL)
	origin->next->prev = new;
      origin->next = new;
    }
  return (origin);
}

t_list		*my_get_next_struct(size_t i, t_list *start)
{
  t_list	*ptr;

  ptr = start + 1 + my_get_size_alloc(i);
  return (ptr);
}

int	my_get_size_alloc(size_t size)
{
  int	i;

  i = size / sizeof(t_list) + 1;
  return (i);
}
