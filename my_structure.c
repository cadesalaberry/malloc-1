/*
** my_structure.c for malloc in /media/dwarfnet/DATA/REV/Malloc/lib
**
** Made by DwarfNet
** Login   <dwarfnet@epitech.net>
**
** Started on  Thu Jun 18 14:51:30 2015 DwarfNet
** Last update Fri Jun 26 14:40:18 2015 DwarfNet
*/

#include "h_main.h"

static t_list	*my_struct(t_list *set)
{
  static t_list	*get = NULL;

  if (set != NULL)
    get = set;
  else
    set = get;
  return (set);
}

void	my_set_static(t_list *set)
{
  set = my_struct(set);
}

t_list		*my_get_static(t_list *ptr)
{
  size_t	size;

  ptr = my_struct(NULL);
  if (ptr == NULL)
    {
      size = 512 - sizeof(t_list);
      if ((ptr = sbrk(512)) == NULL)
	return (NULL);
      ptr = my_init_list(NULL, NULL, size, ptr);
      ptr->ptr = ptr + 1;
      my_set_static(ptr);
    }
  return (ptr);
}
